#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>

const int N = 3e5 + 5;
vector<pair<int, int>> adj[N];
int vis[N];
vector<int> dp(N, 1e18);
int n, m, k;
const int N = 3e5 + 5;
const int INF = 1e18;

vector<pair<int, int>> adj[N];

vector<int> dijkstra(int s) {
    vector<int> dist(N, INF);
    using T = pair<int, int>;
    priority_queue<T, vector<T>, greater<>> pq;
    dist[s] = 1e18;
    pq.emplace(dist[s], s);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) {
            continue;
        }
        for (auto [w, v] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int check(int mid) {
    int resp = dfs(1, 0, mid);
    return resp <= k;
}

void solve () {
    cin >> n >> m >> k;
    priority_queue<pii, vector<pii>, greater<int>> pq;

    for (int i=0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
        pq.emplace({w, 
    }

    int l = 0;
    int r = 1e9 + 1;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;

        for (int i=0; i <= n; i++) {
            vis[i] = 0;
            dp[i] = 1e18;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
