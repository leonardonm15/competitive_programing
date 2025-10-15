#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 4e3 + 5;
const int MOD = 998244353;
int dp[N];

void solve () {
    int n, k; cin >> n >> k;

    dp[n] = 1;


    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (i + j > n) break;
            if (j == k) continue;
            dp[i] += dp[i + j];
            dp[i] %= MOD;
        }
    }

    cout << dp[0] << endl;
    return;

    for (int jump = n; jump >= 1; jump--) {
        if (jump == k) continue;
        for (int i = n - jump; i >= 0; i -= jump) {
            dp[i] += dp[i + jump];
            dp[i] %= MOD;
        }
    }

    cout << dp[0] << endl;

}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
