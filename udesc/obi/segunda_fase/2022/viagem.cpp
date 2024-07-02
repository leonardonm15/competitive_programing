#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define ll long long
//#define int long long
#define pii tuple<int, int, int>

const int N = 1e4 + 5;
const int V = 200 + 5;
const int INF = 2e9 + 5;

vector<pii> adj[N];
int dist[N][V];

int djks(int root, int pm, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // tempo, valor, v
    dist[root][0] = 0;
    // pra esse valor monetario, qual é a menor quantidade de tempo
    pq.push({0, 0, root});

    while (pq.size()) {
        auto [d, p, u] = pq.top();
        pq.pop();
        if (d > dist[u][p]) continue; // dist[u][p] contains t
        for (auto [t, w, v]: adj[u]) {
            if (w + p <= pm && dist[v][w + p] > d + t) {
                dist[v][w + p] = d + t;
                pq.push({d + t, w + p, v});
            }
        }
    }

    int resp = INF;
    for (int i = 0; i <= pm; i++) resp = min(resp, dist[n][i]);

    return (resp == INF ? -1 : resp);
}

void solve () {
    int v, n, m; cin >> v >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, t, w; cin >> u >> v >> t >> w;
        adj[u].push_back({t, w, v});
        adj[v].push_back({t, w, u});
    }

    int x, y; cin >> x >> y;

    cout << djks(x, v, y) << endl;
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
