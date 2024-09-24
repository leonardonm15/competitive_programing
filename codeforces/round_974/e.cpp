#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define tii tuple<int, int, int>

const int N = 2e5 + 5;

vector<pair<int, int>> adj[N];
vector<int> dist(n);

void djks(int root, int h) {
    dist[root] = 0;
    priority_queue<tii> pq; // distancia_atual nodo quantidade de hs
    pq.push_back(dist[root], root, h);

    while (!pq.empty) {
        
    }
}

void solve () {
    int n, m, h; cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
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
