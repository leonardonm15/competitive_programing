#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
int n;
const int N = 2500 + 5;
const int INF = -1 * 1e11;
vector<pair<int, int>> adj[N];
int dist[N];
int cor[N];
int vis[N];
vector<tuple<int, int, int>> edg;
bool flag = false;
int h = 1;

void dfs(int u) {
    vis[u]++;
    if (u == n) {
        flag = true;
        return;
    }
    for (auto [v, w]: adj[u]) {
        if (!vis[v]) dfs(v);
    }
}
 
void belman_ford(int root) {
    dist[root] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w]: edg) {
            if (dist[u] > INF) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }


    for (auto [u, v, w]: edg) {
        if (dist[u] > INF && dist[u] + w > dist[v]) {
            dfs(v);
            dist[v] = -INF;
            if (flag) return;
        }
    }

}
 
void solve () {
    int m; cin >> n >> m;
    for (int i=0; i <= n; i++) dist[i] = INF;
    
    for (int i=0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        edg.push_back({u, v, w});
    }
 
    belman_ford(1);


    cout << (flag ? -1 : dist[n]) << endl;
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
