#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
int vis[N], sz[N], tin[N], low[N];
int n;
int t = 0;
int resp = 0;

void dfs(int u, int p) {
    vis[u]++;
    low[u] = tin[u] = t++;
    for (auto v: adj[u]) {
        if (!vis[v]) {
            dfs(v, u);
            low[u] = min({low[u], low[v]});
            sz[u] += sz[v];
        }
        if (vis[v] && v != p) low[u] = min(low[u], tin[v]);
    }

    if (low[u] == tin[u]) {
        // total de rotas = (n * (n - 1)) / 2
        // quantidade de caras que eu vou tirar (sz[u] * (n - sz[u])) / 2
        // total de rotas - (maior quantidade de rotas que eu vou tirar);
        int x = sz[u] * (n - sz[u]);
        resp = max(resp, x);
    }
}

void solve () {
    int m; cin >> n >> m;
    int total = (n * (n - 1)) / 2;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) sz[i] = 1;
    dfs(1, 1);

    cout << total - resp << endl;
    resp = 0;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        low[i] = 0;
        tin[i] = 0;
        vis[i] = 0;
        sz[i] = 1;
    }
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
