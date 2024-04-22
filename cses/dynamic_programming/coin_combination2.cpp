#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int MOD = 1e9 + 7;

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> dp(1e6 + 5);
    dp[0] = 1;
    for (int i=0; i < n; i++) cin >> arr[i];
    for (auto coin: arr) {
        for (int i=0; i <= k; i++) {
            if (dp[i] >= 1 && i + coin <= k) {
                dp[i + coin] += dp[i];
                dp[i + coin] %= MOD;
            }
        }
    }

    cout << dp[k] << endl;
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
