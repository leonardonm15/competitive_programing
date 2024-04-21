#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int MOD = 1e9 + 7;

void solve () {
    int n; cin >> n >> k;
    vector<int> arr(n);
    vector<int> dp(3e6);
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;
        dp[num]++;
    }

    for (int i=1; i <= k; i++) {
        if (dp[i] == 0) continue;
        for (auto cara: arr) {
            dp[i + cara] += dp[i];
            dp[i + cara] %= d
        }
    }

    /* for (int i=0; i < n; i++) { */
    /*     calc(arr[i], arr[i], arr); */
    /* } */

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
