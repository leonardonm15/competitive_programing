#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> vis(N);
vector<pair<int, int>> tin(N);
vector<int> dp(N, 0);

void dfs(int u) {
    vis[u]++;
    int mxc = 0;
    for (auto v: adj[u]) {
        if (!vis[v]) dfs(v);
        mxc = max(mxc, dp[v]);
    }

    dp[u] += mxc;
    return;
}

void solve () {
    int n, m; cin >> n >> m;

    for (int i=0; i <= n; i++) {
        tin[i].second = i + 1;
    }
    for (int i=0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        tin[v].first++;
    }

    sort(tin.begin(), tin.begin() + n);
    int resp = 0;
    for (int i=0; i < n; i++) {
        if (!tin[i].first) {
            dfs(i);
            resp = max(resp, dp[i]);
        }
    }
    cout << resp << endl;
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
