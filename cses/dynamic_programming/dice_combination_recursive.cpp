#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int N = 2e6;
const int MOD = 1e9 + 7;
vector<int> dp(N, 0);

int calc(int n) {
    if (dp[n] > 0) return dp[n];
    for (int i=1; i <= 6; i++) {
        if (n - i >= 0) dp[n] += calc(n - i);
        dp[n] %= MOD;
    }

    return dp[n];
}

void solve () {
    int n; cin >> n;
    dp[1] = 1;
    dp[0] = 1;
    calc(n);
    cout << dp[n] << endl;
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
