#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e3 + 5;
vector<int> adj[N];
int vis[N];

void dfs(int u, int s) {
    vis[u]++;
    for (auto v: adj[u]) {
        if (!vis[v] && v != s) {
            dfs(v, s);
        }
    }
}

void solve () {
    int n, q; cin >> n >> q;
    
    for (int i=0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (q--) {
        int l, e, s; cin >> l >> e >> s;
        dfs(l, s);
        cout << (vis[e] ? "SIM" : "NAO") << endl;
        for (int i=0; i <= n; i++) vis[i] = 0;
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
