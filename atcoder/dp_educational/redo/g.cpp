#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>

const int N = 1e5 + 5;

vector<pii> adj[N];
int dist[N];

int djks(int root) {
    dist[root] = 0;
}

void solve () {
    int n, m; cin >> n >> m;

    for (int i = 0; i <= n; i++) dist[i] = -1;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back({v, 1});
    }
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
