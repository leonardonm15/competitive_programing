
#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>
#define tii tuple<int, int, int>

const int N = 2e5 + 5;
const int INF = 1e18;

vector<pii> adj[N];
int dist[2][N];
int horse[N];

void djks(int root) {
    dist[horse[root]][root] = 0;
    priority_queue<tii> pq; // distancia_atual nodo quantidade de hs
    pq.push({dist[horse[root]][root], root, horse[root]});

    while (!pq.empty()) {
        auto [d, u, cav] = pq.top();
        cout << "------------------" << endl;
        cout << "d -> " << d << endl;
        cout << "u -> " << u << endl;
        cout << "cav -> " << cav << endl;
        pq.pop();

        if (dist[cav][u] < d) continue;

        for (auto [v, w]: adj[u]) {
            if (d + w < dist[cav][v]) {
                dist[cav | horse[v]][v] = d + (cav ? w/2 : w);
                pq.push({dist[cav | horse[v]][v], v, (cav | horse[v])});
            }
        }
    }
}

void solve () {
    int n, m, h; cin >> n >> m >> h;

    for (int i = 0; i <= n; i++) {
        dist[0][i] = INF;
        dist[1][i] = INF;
    }


    for (int i = 0; i < h; i++) {
        int aga; cin >> aga;
        horse[aga]++;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    djks(1);

    cout << "dist -> ";
    for (int i = 1; i <= n; i++) { cout << dist[0][i] << " "; }
    cout << endl;
    for (int i = 1; i <= n; i++) { cout << dist[1][i] << " "; }
    cout << endl;

    if (dist[0][n] == INF && dist[1][n] == INF) {
        cout << -1 << endl;
        return;
    } 
    
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
