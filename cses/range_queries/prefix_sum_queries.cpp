#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int neutral = 0;

struct node {
    int soma;
    int ans;
    node () {
        soma = neutral;
        ans = neutral;
    }

    node (int s, int a) {
        soma = s;
        ans = a;
    }
};

vector<node> seg;
int n;

node merge(node a, node b) {
    node resp;
    resp.soma = a.soma + b.soma;
    resp.ans = max(a.ans, a.soma + b.ans);
    return resp;
}

node query(int u, int l, int r, int L, int R) {
    int mid = (l + r) >> 1;
    if (l >= L && r <= R) return seg[u];
    else if (l > R || r < L) return node();
    else {
        node resp = merge(query(u * 2, l, mid, L, R), query(u * 2 + 1, mid + 1, r, L, R));
        return resp;
        /* return resp.ans; */
    }
}

node query(int l, int r) {
    return query(1, 0, n - 1, l, r);
}

void update(int u, int l, int r, int i, int k) {
    if (l == r) {
        seg[u].soma = k;
        seg[u].ans = max(0ll, k);
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) update(u * 2, l, mid, i, k);
    else update(2 * u + 1, mid + 1, r, i, k);
    seg[u] = merge(seg[2 * u], seg[2 * u + 1]);
}

void update(int i, int k) {
    update(1, 0, n - 1, i, k);
}

void build(int u, int l, int r, vector<int>& v) {
    if (l == r) {
        seg[u].soma = v[l];
        seg[u].ans = max(0ll, v[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(u * 2, l, mid, v);
    build(u * 2 + 1, mid + 1, r, v);
    seg[u] = merge(seg[u * 2], seg[u * 2 + 1]);
}
void build(vector<int> &v) {
    seg.resize(4 * n, node());
    build(1, 0, n - 1, v);
}

void solve () {
    int q; cin >> n >> q;
    vector<int> arr(n);

    for (int i=0; i < n; i++) cin >> arr[i];

    build(arr);
    while (q--) {
        int t; cin >> t;
        if (t&1) {
            int i, k; cin >> i >> k;
            i--;
            update(i, k);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            node c = query(l, r);
            cout << c.ans << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
