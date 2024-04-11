#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int dp[201][201][201];

int calc(int q1, int q2, int q3) {
    if (min({q1, q2, q3}) < 0) return 0;
    if (dp[q1][q2][q3] != -1) return dp[q1][q2][q3];

    int xor_geral = (q1&1? 1: 0) ^ (q2&1? 2: 0) ^ (q3&1? 3: 0);
    dp[q1][q2][q3] = max({
            calc(q1 - 1, q2, q3), 
            calc(q1, q2 - 1, q3),
            calc(q1, q2, q3 - 1),
            }) + (xor_geral == 0);
    return dp[q1][q2][q3];
}

void solve () {
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << (dp[a][b][c] + (d / 2)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    calc(200, 200, 200);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
