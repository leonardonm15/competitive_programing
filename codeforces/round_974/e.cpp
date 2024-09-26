#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
// #define tii tuple<int, int, int>
#define pii pair<int, int>

const int N = 2e5 + 5;
const int INF = 1e18;

vector<pii> adj[N];
vector<int> dist(N, INF);
vector<int> distn(N, INF);
vector<int> horse(N);

void djks(int root, vector<int>& dist) {
    dist[root] = 0;
    priority_queue<pii> pq; // distancia_atual nodo quantidade de hs
    pq.push({dist[root], root});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u] < d) continue;

        for (auto [v, w]: adj[u]) {
            cout << "--------------" << endl;
            cout << "u -> " << u << endl;
            cout << "v -> " << v << endl;
            cout << "w -> " << w << endl;
            cout << "d -> " << d << endl;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve () {
    int n, m, h; cin >> n >> m >> h;

    for (int i = 0; i < h; i++) {
        int aga; cin >> aga;
        horse[aga]++;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }


    djks(1, dist);
    djks(n, distn);

    cout << "dist -> ";
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    cout << "distn -> ";
    for (int i = 1; i <= n; i++) {
        cout << distn[i] << " ";
    }
    cout << endl;

    if (dist[n] == INF) {
        cout << -1 << endl;
        return;
    } 
    
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
