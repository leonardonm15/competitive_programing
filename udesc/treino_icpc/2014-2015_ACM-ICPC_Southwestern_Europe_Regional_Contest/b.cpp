#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define ii pair<int, int>
#define int long long

const int MAX = 1e4 + 5;
const int INF = 1e18 + 5;
vector<ii> adj[MAX];
vector<int> dist(MAX, 1e18 + 5);
vector<int> vis(MAX);
int resp = 0;

int dk(int s) {
    priority_queue<ii, vector<ii>, greater<ii>> fila;
    dist[s] = 0;
    fila.emplace(dist[s], s);
    while (!fila.empty()) {
        auto [d, u] = fila.top();
        /* cout << "----------" << endl; */
        /* cout << "d -> " << d << endl; */
        /* cout << "u -> " << u << endl; */
        fila.pop();
        if (d != dist[u]) continue;
        for (auto [w, v]: adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                fila.emplace(dist[v], v);
            }
        }
        /* cout << "dist[u] -> " << dist[u] << endl; */
    }
    return -1;
}

void dfs(int u) {
    vis[u]++;
    for (auto [w, v]: adj[u]) {
        if (dist[v] == dist[u] - w) {
            resp += w;
            if (!vis[v]) dfs(v);
        }
    }
}

void solve () {
    int n, m; cin >> n >> m;
    for (int i=0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        if (a == b) continue;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    dk(0);
    vis[0]++;
    dfs(n - 1);
    cout << 2 * resp << endl;
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
