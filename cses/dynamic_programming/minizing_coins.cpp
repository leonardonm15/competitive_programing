#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int NINF = 1e15;

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> dp(3e6 + 5, NINF);

    for (int i=0; i < n; i++) cin >> arr[i];

    for (auto cara: arr) dp[cara] = 1;

    for (int i=1; i <= k; i++) {
        for (auto cara: arr) {
            if (dp[i] >= 1) dp[i + cara] = min(dp[i + cara], dp[i] + 1);
        }
    }

    cout << (dp[k] == NINF ? -1 : dp[k]) << endl;
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
