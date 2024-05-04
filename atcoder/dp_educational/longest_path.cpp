#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
vector<pair<int, int>> tin(N);
vector<int> dp(N, 0);

int dfs(int u) {
    if (!adj[u].size()) return 0;
    if (dp[u] > 0) return dp[u];

    int ans = 0;
    for (auto v: adj[u]) {
        ans = max(ans, dfs(v));
    }

    cout << "----------" << endl;
    cout << "U -> " << u << endl;
    cout << "dp[u] -> " << dp[u] << endl;

    return dp[u] += (ans + 1);
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
    for (int i=1; i <= n; i++) {
        if (!tin[i].first) {
            dfs(tin[i].second);
            resp = max(resp, dp[tin[i].second]);
        }
    }

    /* cout << "caras -> "; */
    /* for (int i=1; i <= n; i++) cout << dp[i] << " "; */
    /* cout << endl; */

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
