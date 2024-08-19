#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

struct SegLazy {
    int n;
    vector<int> seg;
    vector<int> replace;
    vector<int> soma;

    int merge (int u, int v) { return u + v; }

    int lc (int u) { return 2 * u; }
    int rc (int u) { return 2 * u + 1; }

    void push(int u, int l, int r) {
        // pensar sobre casos -> soma replace && replace -> soma
        // 
        if (replace[u] != -1) {
            if (l != r) {
                soma[lc(u)] = 0; // só zero a soma do filho pq oq importa
                                 // é a minha soma atual
                replace[lc(u)] = replace[u];

                soma[rc(u)] = 0;
                replace[rc(u)] = replace[u];
            }

            seg[u] = replace[u] * (r - l + 1);
            replace[u] = -1;
        }

        if (soma[u] > 0) {
            seg[u] += soma[u] * (r - l + 1);
            if (l != r) {
                soma[lc(u)] += soma[u];
                soma[rc(u)] += soma[u];
            }
            soma[u] = 0;
        }
    }

    void update_soma(int u, int l, int r, int L, int R, int x) {
        /* cout << "antes do push: u: " << u << " | seg[u]: " << seg[u] << " | soma[u]: " << soma[u] << " | x: " << x << endl; */
        push(u, l, r);
        /* cout << "dps do push: u: " << u << " | seg[u]: " << seg[u] << " | soma[u]: " << soma[u] << " | x: " << x << endl; */
        if (l > R || r < L) { return; }
        if (l >= L && r <= R) { 
            /* cout << "antes do push: u: " << u << " | seg[u]: " << seg[u] << " | soma[u]: " << soma[u] << " | x: " << x << endl; */
            soma[u] += x; 
            push(u, l, r);
            /* cout << "dps do push: u: " << u << " | seg[u]: " << seg[u] << " | soma[u]: " << soma[u] << " | x: " << x << endl; */
        }
        else {
            int mid = (l + r) >> 1;
            update_soma(lc(u), l, mid, L, R, x);
            update_soma(rc(u), mid + 1, r, L, R, x);
            seg[u] = merge(seg[lc(u)], seg[rc(u)]);
        }
    }
    void update_soma(int l, int r, int x) {
        update_soma(1, 0, n - 1, l, r, x);
    }

    void update_replace(int u, int l, int r, int L, int R, int x) {
        push(u, l, r);
        if (l > R || r < L) { return; }
        if (l >= L && r <= R) { 
            replace[u] = x;
            push(u, l, r);
        } else {
            int mid = (l + r) >> 1;
            update_replace(lc(u), l, mid, L, R, x);
            update_replace(rc(u), mid + 1, r, L, R, x);
            seg[u] = merge(seg[lc(u)], seg[rc(u)]);
        }
    }
    void update_replace(int l, int r, int x) {
        update_replace(1, 0, n - 1, l, r, x);
    }

    int query(int u, int l, int r, int L, int R) {
        push(u, l, r);
        if (l > R || r < L) { return 0; }
        if (l >= L && r <= R) { return seg[u]; }
        else {
            int mid = (l + r) >> 1;
            int r1 = query(lc(u), l, mid, L, R);
            int r2 = query(rc(u), mid + 1, r, L, R);
            return merge(r1, r2);
        }
    }
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void build (int u, int l, int r, const vector<int>& vec) {
        if (l == r) {
            seg[u] = vec[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(lc(u), l, mid, vec);
        build(rc(u), mid + 1, r, vec);
        seg[u] = merge(seg[lc(u)], seg[rc(u)]);
    }
    void build (const vector<int>& vec) {
        n = vec.size();
        seg.assign(4 * n, 0);
        replace.assign(4 * n, -1);
        soma.assign(4 * n, 0);
        build(1, 0, n - 1, vec);
    }
};

void solve () {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegLazy seg;
    seg.build(arr);

    while (q--) {
        int t; cin >> t;

        if (t == 1) { // soma em range l r x
            int l, r, x; cin >> l >> r >> x;
            l--; r--;
            seg.update_soma(l, r, x);
        }

        if (t == 2) { // assign em range l, r, x
            int l, r, x; cin >> l >> r >> x;
            l--, r--;
            seg.update_replace(l, r, x);
        }

        if (t == 3) { // soma dos valores em range l r
            int l, r; cin >> l >> r;
            l--; r--;
            cout << seg.query(l, r) << endl;
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
