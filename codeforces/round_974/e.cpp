
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
        horse[i] = 0;
        adj[i].clear();
        dist[0][i] = INF;
        dist[1][i] = INF;
        ndist[0][i] = INF;
        ndist[1][i] = INF;
    }
}

void djks(int root, int dist[2][N]) {
    dist[horse[root]][root] = 0;
    priority_queue<tii, vector<tii>, greater<tii>> pq; // distancia atual, nodo, estou montado ?
    pq.push({dist[horse[root]][root], root, horse[root]});
    
    while (!pq.empty()) {
        auto [d, u, montado] = pq.top();

        pq.pop();

        if (!montado && horse[u]) {
            if (d < dist[1][u]) dist[1][u] = d;
            else continue;
            montado = 1;
        }


        if (dist[montado][u] < d) continue;

        for (auto [v, w]: adj[u]) {

            int k = d + (montado ? w / 2 : w);
            if (dist[montado][v] > k) {
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

    /* cout << "dist -> "; */
    /* for (int i = 1; i <= n; i++) { cout << dist[0][i] << " "; } */
    /* cout << endl; */
    /* for (int i = 1; i <= n; i++) { cout << dist[1][i] << " "; } */
    /* cout << endl; */

    /* cout << "-----------" << endl; */

    /* cout << "ndist -> "; */
    /* for (int i = 1; i <= n; i++) cout << ndist[0][i] << " "; */
    /* cout << endl; */
    /* for (int i = 1; i <= n; i++) cout << ndist[1][i] << " "; */
    /* cout << endl; */

    int resp = INF;
    for (int i = 1; i <= n; i++) {
        int d = INF;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                d = min(d, max(dist[j][i], ndist[k][i]));
            }
        }

        resp = min(resp, d);
    }

    cout << (resp == INF ? -1 : resp) << endl;
    clear_tc(n);
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
