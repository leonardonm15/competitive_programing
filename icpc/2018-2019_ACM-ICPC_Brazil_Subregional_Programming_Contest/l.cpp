#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
int sz[N];
int head[N];

struct hld {
    vector<int> arvere;
    void dfs_chain(int u, int p) {
        for (auto v: adj[u]) if (v != p) {
            if (v == adj[u][0]) head[v] = head[u];
            else head[v] = v;
            dfs_chain(v, u);
        }
    }

    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (auto v: adj[u]) {
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
            }
        }

        for (int i=0; i < adj[u].size(); i++) {
            if (sz[adj[u][i]] > sz[adj[u][0]] || adj[u][0] == p) swap(adj[u][0], adj[u][i]);
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

    dfs_sz(1, -1);
    head[1] = 1;
    dfs_chain(1, 1);
    
    cout << "color -> ";
    for (int i=0; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;

    cout << "sz -> ";
    for (int i=0; i < n; i++) {
        cout << sz[i] << " ";
    }
    cout << endl;
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
