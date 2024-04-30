#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> vis(N);
vector<pair<int, int>> tin(N);
vector<int> dp(N, 0);
int resp = 0;

void dfs(int u) {
    vis[u]++;
    for (auto v: adj[u]) {
        if (!vis[v]) dfs(v);
        dp[u] = max(dp[u], dp[u] + dp[v]);
    }
    resp = max(resp, dp[u]);
}

void solve () {
    int n, m; cin >> n >> m;

    for (int i=0; i <= n; i++) {
        tin[i].second = i + 1;
    }
    for (int i=0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        tin[v].first++;
    }

    sort(tin.begin(), tin.begin() + n);

    cout << resp << endl;
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
