#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define ll long long

struct Node {
    int x = 0;
    multiset<int> xoradas;
};

struct Segree {
    Node merge(Node a, Node b) { 
        Node c;
        c.x = a.x ^ b.x;
    }
    const Node neutral;
    int n;
    vector<Node> t;

    void build(int u, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[u].x = v[l];
            t[u].xoradas.emplace(v[l]);
        } else {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid, v);
            build(u << 1 | 1, mid + 1, r, v);
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }

    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n << 2, neutral);
    }

    void build(const vector<ll> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n << 2, neutral);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }

    Node query(int u, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u];
        }
        int mid = (l + r) >> 1;
        Node ql = query(u << 1, l, mid, L, R);
        Node qr = query(u << 1 | 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int u, int l, int r, int i, ll x) {
        if (l == r) {
            t[u] += x; // soma
            // t[u] = x; // substitui
        } else {
            int mid = (l + r) >> 1;
            if (i <= mid) {
                update(u << 1, l, mid, i, x);
            } else {
                update(u << 1 | 1, mid + 1, r, i, x);
            }
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }
    void update(int i, ll x) { update(1, 0, n - 1, i, x); }
};

void solve () {

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
