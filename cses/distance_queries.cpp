#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
vector<int> vis(maxn);
vector<int> depth(maxn);
vector<vector<int>> up(maxn, vector<int>(20));

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u];
    // v sempre mais profundo que u;
    for (int i=19; i >= 0; i--) {
        if (d & (1 << i)) {
            v = up[v][i];
        }
    }

    if (v == u) return v;

    for (int i=19; i >= 0; i--) {
        int pu = up[u][i];
        int pv = up[v][i];
        if (pu != pv) {
            u = pu;
            v = pv;
        }
    }

    return up[v][0];
}

void dfs(int u, int p, int t) {
    vis[u]++;
    depth[u] = t;
    up[u][0] = p;

    for (int i=1; i < 20; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (auto v: adj[u]) {
        if (!vis[v]) dfs(v, u, t + 1);
    }

}

void solve () {
    int n, q; cin >> n >> q;
    int root;
    for (int i=0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1, 0);

    while (q--) {
        int a, b; cin >> a >> b;
        int parent = lca(a, b);
        /* cout << "parent -> " << parent << endl; */
        cout << (depth[a] - depth[parent]) + (depth[b] - depth[parent]) << endl;
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
