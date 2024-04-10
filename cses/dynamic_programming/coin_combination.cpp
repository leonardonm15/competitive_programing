#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
 
const int maxx = 1e6 + 5;
const int mod = 1e9 + 7;
 
void solve () {
    int n, k; cin >> n >> k;
    vector<int> dp(maxx);
    vector<int> coins(n);

    for (int i=0; i < n; i++) {
        cin >> coins[i];
        dp[coins[i]]++;
    }
 
 
    for (int i=0; i < maxx; i++) {
        if (dp[i]) {
            for (auto c: coins) if (i + c <= k) {
                dp[i + c] += dp[i];
                dp[i + c] %= mod;
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
