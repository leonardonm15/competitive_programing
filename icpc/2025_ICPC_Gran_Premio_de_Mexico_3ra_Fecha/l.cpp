#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define tii tuple<int, int, int>

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;

vector<pair<int, int>> adj[N];

struct SegTree {
    int merge(int a, int b) {
        if (a + b >= MOD) return (a + b) - MOD;
        else return a + b; 
    }
    const int neutral = 0;
    int n;
    vector<int> t, lazy;
    vector<bool> replace;
    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }
    void push(int p, int l, int r) {
        if (lazy[p] != 1) {
            t[p] = (t[p] * lazy[p]) % MOD;
            if (l != r) {
                lazy[lc(p)] = (lazy[lc(p)] * lazy[p]) % MOD;
                lazy[rc(p)] = (lazy[rc(p)] * lazy[p]) % MOD;
            }
        }
        lazy[p] = 1;
    }
    void build(int p, int l, int r, const vector<int> &v) {
        if (l == r) {
            t[p] = v[l];
        } else {
            int mid = (l + r) / 2;
            build(lc(p), l, mid, v);
            build(rc(p), mid + 1, r, v);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void build(const vector<int> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 4, neutral);
        lazy.assign(n * 4, 1);
        replace.assign(n * 4, false);
        build(1, 0, n - 1, v);
    }
    int query(int p, int l, int r, int L, int R) {
        push(p, l, r);
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        int mid = (l + r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int p, int l, int r, int L, int R, int val, bool repl = 0) {
        push(p, l, r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            lazy[p] = val;
            replace[p] = repl;
            push(p, l, r);
        } else {
            int mid = (l + r) / 2;
            update(lc(p), l, mid, L, R, val, repl);
            update(rc(p), mid + 1, r, L, R, val, repl);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void update(int l, int r, int val, bool repl) { update(1, 0, n - 1, l, r, val, repl); }
    void sumUpdate(int l, int r, int val) { update(l, r, val, 0); }
    void setUpdate(int l, int r, int val) { update(l, r, val, 1); }
};

namespace HLD {
    int t, sz[N], pos[N], par[N], head[N];
    SegTree seg; // por padrao, a HLD esta codada para usar a SegTree lazy,
                 // mas pode usar qualquer estrutura de dados aqui
    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            auto &[v, w] = adj[u][i];
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0].first] || adj[u][0].first == p)
                    swap(adj[u][0], adj[u][i]);
            }
        }
    }
    void dfs_hld(int u, int p = -1) {
        pos[u] = t++;
        for (auto [v, w] : adj[u]) {
            if (v != p) {
                par[v] = u;
                head[v] = (v == adj[u][0].first ? head[u] : v);
                dfs_hld(v, u);
            }
        }
    }
    void build_hld(int u) {
        dfs_sz(u);
        t = 0, par[u] = u, head[u] = u;
        dfs_hld(u);
    }
    void build(int n, int root) {
        build_hld(root);
        vector<int> aux(n + 1, seg.neutral);
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : adj[u]) {
                if (u == par[v]) aux[pos[v]] = w;
            }
        }
        seg.build(aux);
    }
    int query(int u, int v) {
        if (u == v) return seg.neutral;
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) {
            return seg.query(pos[u] + 1, pos[v]);
        } else {
            int qv = seg.query(pos[head[v]], pos[v]);
            int qu = query(u, par[head[v]]);
            return seg.merge(qu, qv);
        }
    }
    int query_subtree(int u) {
        if (sz[u] == 1) return seg.neutral;
        return seg.query(pos[u] + 1, pos[u] + sz[u] - 1);
    }
    // a flag repl diz se o update é de soma ou de replace
    void update(int u, int v, int k, bool repl) {
        if (u == v) return;
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) {
            seg.update(pos[u] + 1, pos[v], k, repl);
        } else {
            seg.update(pos[head[v]], pos[v], k, repl);
            update(u, par[head[v]], k, repl);
        }
    }
    void update_subtree(int u, int k, bool repl) {
        if (sz[u] == 1) return;
        seg.update(pos[u] + 1, pos[u] + sz[u] - 1, k, repl);
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return head[u] == head[v] ? u : lca(u, par[head[v]]);
    }
}

void solve () {
    int n, q; cin >> n >> q;
    vector<int> arr;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }


    HLD::build(n, 0);
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        HLD::update(l - 1, r - 1, x, 0);
        cout << HLD::query(l - 1, r - 1) << endl;
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
