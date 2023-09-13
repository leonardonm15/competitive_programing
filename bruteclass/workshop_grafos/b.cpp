#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
vector<bool> vis(maxn);
vector<int> dp(maxn);

void dfs(int n) {
    vis[n] = true;
    for (auto cara: adj[n]) {
        dfs(cara);
        dp[n] += dp[cara]
    }
}

void solve () {
    int n; cin >> n;
    for (int i=2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
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
