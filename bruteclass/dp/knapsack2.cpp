#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 105;
const int maxv = 100 * 1e3 + 5;

void solve () {
    vector<vector<int>> dp(maxn, vector<int>(maxv, 2e9));
    dp[0][0] = 0;
    int n, w; cin >> n >> w;
    int peso, val;
    int maxj = 0;
    for (int i=1; i <= n; i++) {
        cin >> peso >> val;
        for (int j=0; j <= maxv - 5; j++) {
            int last = dp[i-1][j];
            if (j >= val && (peso + dp[i-1][j-val]) <= last) {
                dp[i][j] = peso + dp[i-1][j-val];
                if (dp[i][j] <= w) maxj = max(maxj, j);
            } else dp[i][j] = last;
        }
    }
    cout << maxj << endl;
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
