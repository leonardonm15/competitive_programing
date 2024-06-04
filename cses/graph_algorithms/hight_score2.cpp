#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int n;
const int INF = 1e9 * -1;
vector<tuple<int, int, int>> edg;

vector<int> bellman_ford(int s) {
    vector<int> dist(n + 1, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edg) {
            if (dist[u] < INF) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    for (auto [u, v, w] : edg) {
        if (dist[u] < INF && dist[u] + w < dist[v]) {
            dist[v] = -INF;
        }
    }

    cout << "dists -> ";
    for (int i=1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return dist;
}

void solve () {
    int m; cin >> n >> m;

    for (int i=0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edg.push_back({u, v, w});
    }

    bellman_ford(1);
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
