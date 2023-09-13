#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
vector<bool> vis(maxn);
vector<int> dp(maxn);

int dfs(int n) {
    vis[n] = true;
    if (adj[n].size() == 0) {
        return 0;
    }
    for (auto cara: adj[n]) {
        if (vis[cara]) continue;
        dfs(cara);
        dp[n] += dp[cara] + 1;
    }
    return 0;
}

void solve () {
    int n; cin >> n;
    for (int i=2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
    }
    dfs(1);
    for (int i=1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
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
