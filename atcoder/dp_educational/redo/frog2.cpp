#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    vector<int> dp(n);

    for (int i=1; i < n; i++) {
        int resp = (int)1e18 + 5;
        for (int j=i - 1; j >= max(0ll, i - k); j--) {
            /* cout << "arr[i] - arr[j] -> " << abs(arr[i] - arr[j]) << endl; */
            resp = min(resp, dp[j] + abs(arr[i] - arr[j]));
        }
        dp[i] = resp;
    }

    /* cout << "dp -> "; */
    /* for (auto cara: dp) cout << cara << " "; */
    /* cout << endl; */

    cout << dp[n - 1] << endl;
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
