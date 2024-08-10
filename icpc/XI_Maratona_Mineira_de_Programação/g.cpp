#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define endl '\n'

const int N = 1e5 + 5;
const int INF = 1e18;

vector<pii> adj[N];
int vis[N];
int dist[N][105];

void bfs(int root, int k) {
    queue<pii> q;
    dist[root][0] = 0;
    q.push({0, root});
    while (!q.empty()) {
        auto [p, u] = q.front();
        q.pop();
        
        for (auto [w, v]: adj[u]) {
            if (p + w <= k && dist[u][p] != INF && dist[u][p] + 1 < dist[v][p + w]) {
                /* cout << "-------------" << endl; */
                /* cout << "u -> " << u << endl; */
                /* cout << "v -> " << v << endl; */
                /* cout << "w -> " << w << endl; */
                /* cout << "atual -> " << p + w << endl; */
                dist[v][p + w] = dist[u][p] + 1;
                q.push({p + w, v});
            }
        }
    }
}

void solve() {
    int n, m, k; cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 100; j++) {
            dist[i][j] = INF;
        }
    }

    bfs(1, k);

    int resp = INF;
    for (int i = 0; i <= 100; i++) {
        resp = min(resp, dist[n][i]);
    }
    cout << (resp == INF ? -1 : resp) << endl;
}

signed main() {
    solve();
    return 0;
}
