#include <bits/stdc++.h>

using namespace std;

#define endl '\n'//                  .   .  roborto
#define int long long//              |___|
// :( :3 :D ;_; ;-; '-' :) :c >:(    |o_o|     :O :o :P :T :C :v :| :* O_O O_o 
//                             +-----|. .|-----<3   ___________
//                                   |   |         |  mim de   | 
//                                   -----        < ___________|
//                                   |   |     
//                                  _o_ _o_
//                                      
    
const int N = 50 + 5;
const int F = N * 1e3;
const int NINF = -1 * 1e14;
vector<vector<int>> dp(N, vector<int>(F, NINF));

void solve () {
    int n, x; cin >> n >> x;
    dp[0][0] = 0;
    for (int i=1; i <= n; i++) {
        int c, f; cin >> c >> f;
        for (int j=0; j < F; j++) {
            if ((i > 1 && c > 0) && j - f >= 0 && (dp[i - 1][j - f] + (x - c) >= 0)) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - f] + (x - c));
            else dp[i][j] = dp[i - 1][j];
        }

    }

    int resp = 0;
    for (int i=0; i < F; i++) {
        if (dp[n][i] >= 0) resp = i;
    }

    cout << "resp -> " << resp << endl;
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
