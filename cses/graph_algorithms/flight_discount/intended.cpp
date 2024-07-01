#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii tuple<int, int, int>

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int dist[N][2];

void djks(int root) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[root][0] = 0;
    dist[root][1] = 0;
    pq.push({dist[root][0], root, 0});

    while (pq.size()) {
        auto [d, u, s] = pq.top();
        pq.pop();
        if (d > dist[u][s]) continue;
        for (auto [w, v]: adj[u]) {
            /* cout << "-------------------" << endl; */
            /* cout << "u -> " << u << endl; */
            /* cout << "v -> " << v << endl; */
            /* cout << "w -> " << w << endl; */
            /* cout << "s -> " << s << endl; */
            if (s == 0 && dist[v][0] > dist[u][0] + w) {
                dist[v][0] = dist[u][0] + w;
                pq.push({dist[v][0], v, 0});
            } 
            if (dist[v][1] > dist[u][0] + w / 2 || dist[v][1] > dist[u][1] + w) {
                dist[v][1] = min(dist[u][0] + w / 2, dist[u][1] + w);
                pq.push({dist[v][1], v, 1});
            }
        }
    }
}

void solve () {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    for (int i = 0; i <= n; i++) {
        dist[i][0] = 1e18;
        dist[i][1] = 1e18;
    }

    djks(1);
    cout << min(dist[n][1], dist[n][0]) << endl;
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
