#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int maxn = 500 + 5;
const int inf = 1e18;
vector<vector<int>> dp(maxn, vector<int> (maxn, inf));

void solve () {
    int n, m, q; cin >> n >> m >> q;
    for (int i=0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = min(c, dp[a][b]);
        dp[b][a] = min(c, dp[a][b]);
    }

    for (int i=1; i <= n; i++) dp[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) { 
            for (int j=1; j <= n; j++) {
                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    dp[j][i] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    for (int i=0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (dp[a][b] == inf) {
            cout << -1 << endl;
            continue;
        } else cout << dp[a][b] << endl;
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
