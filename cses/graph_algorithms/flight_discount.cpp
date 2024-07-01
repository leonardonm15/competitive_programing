#include <bits/stdc++.h>

using namespace std;
 
#define int long long
#define piii tuple<int, int, int>
#define pii pair<int, int>
 
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int dist[N];
int ndist[N];

void ndjks(int root) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    ndist[root] = 0;
    pq.push({dist[root], root});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d < dist[u]) continue;
        for (auto [w, v]: adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}
 
void djks(int root) {
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    dist[root] = 0;
    pq.push({dist[root], root, 0});
    while (pq.size()) {
        auto [d, u, mx] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [w, v]: adj[u]) {
            // ndist[eu] + w / 2  OU dist[eu] + w / 2
            int nd = (d + mx) - (mx / 2);
            cout << "-------------" << endl;
            cout << "u -> " << u << endl;
            cout << "v -> " << v << endl;
            cout << "w -> " << w << endl;
            cout << "mx -> " << mx << endl;
            if (w > mx) {
                nd += w / 2;
            } else {
                nd += w;
                nd -= mx;
                nd += (mx / 2);
            }
            if (dist[v] > nd) {
                dist[v] = nd;
                pq.push({nd, v, max(mx, w)});
            }
        }
    }
}
 
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}
 
	for (int i = 0; i <= n; i++) dist[i] = 1e18;
 
    ndijks(1);
	djks(1);
 
    for (int i = 0; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
 
    cout << dist[n] << endl;
}
 
signed main() {
	solve();
}
 
