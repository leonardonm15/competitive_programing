
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
int ndist[2][N];
int horse[N];

void clear_tc(int n) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        dist[0][i] = INF;
        dist[1][i] = INF;
        ndist[0][i] = INF;
        ndist[1][i] = INF;
    }
}

void djks(int root, int dist[2][N]) {
    dist[horse[root]][root] = 0;
    priority_queue<tii> pq; // distancia atual, nodo, estou montado ?
    pq.push({dist[horse[root]][root], root, horse[root]});
    
    while (!pq.empty()) {
        auto [d, u, montado] = pq.top();

        if (!montado && horse[u]) {
            dist[1][u] = d;
            montado = 1;
        }

        pq.pop();

        if (dist[montado][u] < d) continue;

        for (auto [v, w]: adj[u]) {

            if (dist[montado][v] > d + w) {
                int k = d + (montado ? w / 2 : w);
                dist[montado][v] = k;
                pq.push({k, v, montado});
            }
        }
    }

}

void solve () {
    int n, m, h; cin >> n >> m >> h;

    for (int i = 0; i <= n; i++) {
        dist[0][i] = INF;
        dist[1][i] = INF;
        ndist[0][i] = INF;
        ndist[1][i] = INF;
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

    djks(1, dist);
    djks(n, ndist);

    cout << "dist -> ";
    for (int i = 1; i <= n; i++) { cout << dist[0][i] << " "; }
    cout << endl;
    for (int i = 1; i <= n; i++) { cout << dist[1][i] << " "; }
    cout << endl;

    cout << "-----------" << endl;

    cout << "ndist -> ";
    for (int i = 1; i <= n; i++) cout << ndist[0][i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) cout << ndist[1][i] << " ";
    cout << endl;

    if (dist[0][n] == INF && dist[1][n] == INF) {
        cout << -1 << endl;
        clear_tc(n);
        return;
    } 

    /* int resp = 1e18; */
    /* for (int i = 1; i <= n; i++) { */
    /*     int d = dist[1][i] */
    /*     min(resp, */ 
    /* } */
    
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
