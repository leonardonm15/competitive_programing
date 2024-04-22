#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int MOD = 1e9 + 7;
vector<int> dp(1e6 + 10);

/* int calc(int num) { */
/*     for (int i=1; i <= 6; i++) { */
/*         if (num == i) { */
            
/*         } */
/*         if (num - i >= 0) { */
/*             if (dp[num - i] > 0) { */
/*                 dp[num] += dp[num - i]; */
/*                 dp[num] %= MOD; */
/*             } */
/*             else { */
/*                 calc(num - i); */
/*                 dp[num] += (calc(num - i) % MOD); */
/*             } */
/*         } */
/*     } */
/* } */

void solve () {
    int n; cin >> n;
    /* calc(n); */

    for (int i=1; i <= n; i++) dp[i]++;
    vector<int> dp(1e6 + 10);
    for (int i=1; i <= 6; i++) dp[i]++;
    for (int i=1; i <= n; i++) {
        if (dp[i] > 0) {
            for (int j=1; j <= 6; j++) {
                dp[i + j] += dp[i];
                dp[i + j] %= MOD;
            }
        }
    }

    cout << "dp -> ";
    for (int i=1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    /* quantidade de formas que eu consigo chegar no meu cara */
    /* é a soma das quantidades de formas que eu consigo chegar nos meus pais */

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
