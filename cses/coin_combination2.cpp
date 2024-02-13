
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
    vector<vector<int>> dp(n + 1, vector<int>(maxx));
    vector<int> coins(n);

    for (int i=0; i < n; i++) {
        cin >> coins[i];
        dp[coins[i]][coins[i]]++;
    }

    sort(coins.begin(), coins.end());

    // 
    for (int i=0; i <= n; i++) {
        for (int j=0; j < maxx; j++) {
            if (dp[i][j]) {
                for (auto c: coins) if (j + c <= k && c >= i) {
                    dp[c][j + c] = dp[i][j];
                    dp[c][j + c] %= mod;
                }
            }
        }
    }

    int resp = 0;
    for (int i=0; i <= n; i++) {
        if (dp[i][k] > 0) cout << "dp[" << i << "][k] -> " << dp[i][k] << endl;
        resp += dp[i][k];
        resp %= mod;
    }

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
