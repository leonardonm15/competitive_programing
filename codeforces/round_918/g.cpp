#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>
#define tpi tuple<int, int, int>

const int N = 1e3 + 5;
const int INF = 1e18;
vector<pii> adj[N]; // w, v
int dist[N][N];
int bike[N];

int djks(int root, int n) {
    priority_queue<tpi, vector<tpi>, greater<tpi>> pq;
    dist[root][bike[root]] = 0;
    pq.push({0, root, bike[root]});

    while (pq.size()) {
        auto [d, u, s] = pq.top();
        pq.pop();
        if (d > dist[u][s]) continue;
        for (auto [w, v]: adj[u]) {
            int nd = d + (s * w);
            if (dist[v][s] > nd) {
                dist[v][s] = nd;
                if (bike[v] < s) pq.push({nd, v, bike[v]});
                else pq.push({nd, v, s});
            }
        }
    }
    
    int resp = 1e18;
    for (int i = 1; i < N; i++) resp = min(resp, dist[n][i]);

    return resp;
}

void solve () {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) dist[i][j] = INF;
    }

    for (int i = 1; i <= n; i++) cin >> bike[i];

    cout << djks(1, n) << endl;

    for (int i = 0; i <= n; i++) adj[i].clear();
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
