#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
vector<tuple<int, int, int>> edg;
vector<pair<int, int>> adj[N];
int up[20][N];
int st[20][N];
int pai[N];
int depth[N];
int sz[N];

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);

    int resp = 1e18 + 5;
    int d = depth[b] - depth[a];

    for (int i = 19; i >= 0; i--) {
        if (d&(1 << i)) {
            resp = min(resp, st[i][b]);
            b = up[i][b];
        }
    }

    if (a == b) return resp;

    for (int i = 19; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            resp = min(resp, min(st[i][a], st[i][b]));
            a = up[i][a];
            b = up[i][b];
        }
    }

    return min({resp, st[0][a], st[0][b]});
}

void binary_lifting(int n) {
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
            st[i][j] = min(st[i - 1][j], st[i - 1][up[i - 1][j]]);
        }
    }
}

void dfs(int u, int p, int w, int d) {
    up[0][u] = p;
    st[0][u] = w;
    depth[u] = d;
    for (auto [w, v]: adj[u]) {
        if (v != p) dfs(v, u, w, d + 1);
    }
}

int find(int u) {
    return (u == pai[u] ? u : find(pai[u]));
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;

    if (sz[v] > sz[u]) swap(u, v);

    pai[v] = u;
    sz[u] += sz[v];
    return true;
}

void solve () {
    int n, m; cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        pai[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edg.push_back({w, u, v});
    }

    sort(edg.rbegin(), edg.rend());

    for (int i = 0; i < m; i++) {
        auto [w, u, v] = edg[i];
        if (unite(u, v)) {
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
    }

    dfs(1, 1, 1e18, 0);
    binary_lifting(n);

    /* for (int i = 0; i <= n; i++) { */
    /*     for (int j = 0; j <= 19; j++) { */
    /*         cout << st[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}

signed main() {
    // ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
