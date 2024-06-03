#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int n;
const int N = 2500 + 5;
const int INF = -1 * 1e15;
vector<int> adj[N];
int dist[N];
int cor[N];
int vis[N];
vector<tuple<int, int, int>> edg;
bool flag = false;
int h = 1;

void kosa(int u, int c) {
    cor[u] = c;
    vis[u]++;
    for (auto v: adj[u]) if (!vis[v]) kosa(v, c);
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
            if (!cor[v]) kosa(v, h++);
            if (v == n && cor[v] == cor[u]) {
                cout << -1 << endl;
                flag = true;
                return;
            }
            dist[v] = -INF;
        }
    }
}


void solve () {
    int m; cin >> n >> m;
    for (int i=0; i <= n; i++) dist[i] = INF;
    
    for (int i=0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[v].push_back(u);
        edg.push_back({u, v, w});
    }

    belman_ford(1);

    if (dist[n] >= -INF && !flag) {
        cout << -1 << endl;
        return;
    }
    if (!flag) cout << dist[n] << endl;
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
