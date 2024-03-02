#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> c = {15, 10, 6, 3, 1};
void solve () {
    int n; cin >> n;
    vector<int> dp(62, 1e9 + 5);
    dp[0] = 0;
    for (auto cara: c) dp[cara] = 1;
    for (int i=0; i < dp.size(); i++) {
        if (dp[i] >= 1 && dp[i] != 1e9 + 5) {
            for (auto cara: c) {
                if (i + cara <= 30) dp[i + cara] = min({dp[i + cara], dp[i] + 1});
            }
        }
    }


    /* cout << "dp -> "; */
    /* for (auto cara: dp) cout << cara << " "; */
    /* cout << endl; */
    if (n > 30) {
        cout << dp[30] + (2 * ((n - 30) / 30)) + dp[(n - 30) % 30] << endl;
    } else {
        cout << dp[n] << endl;
    }
    /* int resto = (n % 30); */
    /* int nm = 2 * (n / 30); */
    /* cout << "resto -> " << resto << endl; */
    /* cout << "dp[resto] -> " << dp[resto] << endl; */
    /* cout << "nm -> " << nm << endl; */

    /* cout << (n > 60? nm : 0) + dp[resto] << endl; */
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
