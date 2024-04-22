#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> dp(1e6 + 5, 1e9 + 5);
    dp[n] = 0;
    for (int i=n; i > 0; i--) {
        int k = i;
        while (k > 0) {
            int num = k % 10;
            if (num > 0 && i - num >= 0) dp[i - num] = min(dp[i - num], dp[i] + 1);
            k /= 10;
        }
    }

    cout << dp[0] << endl;
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
