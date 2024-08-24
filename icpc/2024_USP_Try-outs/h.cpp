#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long
using ti = tuple<int, int, int>;
using pii = pair<int, int>;

const int N = 1e5 + 5;
const int INF = 1e18;
int dist[N];
vector<ti> adj[N];
pii times[N];

int djks(int root, int n, int t) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[root] = t;
    pq.push({dist[root], root});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u] < d) continue;

        for (auto [v, ti, tf]: adj[u]) {
            int tp = ti + tf;
            if (dist[u] < dist[v] && ((dist[u] % tp) < ti)) {
                dist[v] = dist[u];
                pq.push({dist[u], v});
            } else {
                int df = tp  - (dist[u] % tp);
                if (dist[u] + df < dist[v]) {
                    pq.push({dist[u] + df, v});
                    dist[v] = dist[u] + df;
                }
            }
        }

    }
    
    return dist[n];
}

void solve() {
    int n, m, t; cin >> n >> m >> t;

    for (int i = 0; i <= n; i++) dist[i] = INF;

    for (int i = 0; i < m; i++) {
        int u, v, ta, tf; cin >> u >> v >> ta >> tf;
        adj[u].push_back({v, ta, tf});
        adj[v].push_back({u, ta, tf});
    }

    cout << djks(1, n, t) << endl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

