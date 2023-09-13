#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1676/G

using namespace std;
//#define int long long
const int maxn = 1e5 + 5;
int n;
vector<int> adj[maxn];
int dp[maxn][2];
string color;
int res = 0;

void dfs(int nodo) {
    for (auto nums: adj[nodo]) {
        dfs(nums);
        dp[nodo][0] += dp[nums][0];
        dp[nodo][1] += dp[nums][1];
    }
    if (dp[nodo][0] == dp[nodo][1]) res++;
}

void solve () {
    cin >> n;
    for (int i=2; i <= n; i++) {
        int num; cin >> num;
        adj[num].push_back(i);
    }
    cin >> color;
    for (int i=0; i < n; i++) {
        if (color[i] == 'W') {
            dp[i + 1][0]++;
        } else {
            dp[i + 1][1]++;
        }
    }
    dfs(1);
    cout << res << endl;

    for (int i=0; i<=n; i++) {
        adj[i].clear();
        dp[i][0] = 0;
        dp[i][1] = 0;
        color.clear();
        res = 0;
    }
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
