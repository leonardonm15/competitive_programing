#include <bits/stdc++.h>

using namespace std;
 
#define int long long
#define pii pair<int, int>
 
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int dist[N];
int ndist[N]; // dijikstra normal

void ndjks(int root) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    ndist[root] = 0;
    pq.push({ndist[root], root});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (ndist[u] != d) continue;
        for (auto [w, v]: adj[u]) {
            if (ndist[v] > d + w) {
                ndist[v] = d + w;
                pq.push({ndist[v], v});
            }
        }
    }
}
 
void djks(int root) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[root] = 0;
    pq.push({dist[root], root});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [w, v]: adj[u]) {
            // ndist[eu] + w / 2  OU dist[eu] + w / 2
            int d1 = ndist[u] + w / 2;
            int d2 = dist[u] + w;
            if (dist[v] > min(d1, d2)) {
                dist[v] = min(d1, d2);
                pq.push({min(d1, d2), v});
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
 
	for (int i = 0; i <= n; i++) {
        dist[i] = 1e18;
        ndist[i] = 1e18;
    }
 
    ndjks(1);

	djks(1);
 
    cout << dist[n] << endl;
}
 
signed main() {
	solve();
}
