#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>

const int INF = 1e18;
const int N = 3e5 + 5;
vector<pii> adj[N];
int vis[N];
int n, m, k;

vector<int> bfs01(int s, int mid) {
    vector<int> dist(n + 5, INF);
    deque<int> q;
    dist[s] = 0;
    q.emplace_back(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto [v, w] : adj[u]) {
            w = w > mid;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) {
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            }
        }
    }
    return dist;
}

int check(int mid) {
    vector<int> dists = bfs01(1, mid);
    /* cout << "----------------" << endl; */
    /* cout << "mid -> " << mid << endl; */
    /* cout << "dists[n] -> " << dists[n] << endl; */
    return dists[n] <= k;
}

void solve () {
    cin >> n >> m >> k;

    for (int i=0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
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
