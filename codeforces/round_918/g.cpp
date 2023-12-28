#include <bits/stdc++.h>

# define int long long
using namespace std;
const int maxn = 1000 + 5;
const int inf = 2e17;
vector<pair<int, int>> adj[maxn];
vector<vector<int>> dist(maxn, vector<int>(maxn, inf));
vector<int> bikes(maxn);
vector<int> bike_nodo(maxn, inf);

void djks(int n, int bike) {
    priority_queue< pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>> > pq;
    dist[n][bike] = 0;
    pq.emplace(0, n);
    bike_nodo[n] = bikes[n];
    while(!pq.empty()) {
        int peso = pq.top().first;
        int nodo = pq.top().second;
        int k = min(bike_nodo[nodo], bikes[nodo]);
        pq.pop();
        for (auto [w, cara]: adj[nodo]) {
            if (dist[nodo] + (w * k) < dist[cara]) {
                dist[cara] = dist[nodo] + (w * k);
                int b = min(k, bikes[cara]);
                pq.emplace(make_pair(dist[cara], cara));
                pq.emplace(make_pair(dist[cara] + (dist[nodo] + (w * b)), nodo));
                bike_nodo[nodo] = b;
                /* bike_nodo[cara] = k; */
            }
        }
    }
}

void solve () {
    int n, m; cin >> n >> m;
    for (int i=0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    for (int i=1; i <= n; i++) cin >> bikes[i];
    bike_nodo[1] = bikes[1];
    djks(1, 1);

    int resp = inf;
    for (int i=0; i <= n; i++) {
        resp = min(resp, dist[n][i]);
    }

    for (int i=0; i <= n; i++) {
        adj[i].clear();
        bike_nodo[i] = inf;
        for (int j=0; i <= n; j++) {
            dist[i][j] = inf;
        }
        bikes[i] = 0;
    }

}

signed main() {
    // ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

