#include <bits/stdc++.h>

# define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 2e9;
vector<pair<int, int>> adj[maxn];
vector<int> dist(maxn, inf);

void djks(int n) {
    priority_queue< pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>> > pq;
    dist[n] = 0;
    pq.emplace(0, n);
    while(!pq.empty()) {
        int peso = pq.top().first;
        int nodo = pq.top().second;
        pq.pop();
        for (auto [w, cara]: adj[nodo]) {
            if (dist[nodo] + w < dist[cara]) {
                dist[cara] = dist[nodo] + w;
                pq.emplace(make_pair(dist[cara], cara));
            }
        }
    }
}

void solve () {
    int n, m; cin >> n >> m;
    for (int i=0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    djks(1);
    for (int i=1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
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
