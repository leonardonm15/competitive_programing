#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>
#define tp tuple<int, int, int>

const int N = 2505
const int INF = 1e18;

vector<pii> adj[N];
vector<tps> edg;
int dist[N];

void bf() {
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto [w, u, v]: edg) {
            
        }
    }


}

void solve () {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int w, u, v; cin >> u >> v >> w;
        edg.push_back({w, u, v});
        adj[u].push_back({w, v});
    }

    for (int i = 0; i <= n; i++) dist[i] = INF;

    bf();
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
