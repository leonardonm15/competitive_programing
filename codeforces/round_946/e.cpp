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
const int NINF = -1 * 1e18;
const int BOMBA = 1e5;
int dp[N][BOMBA];

void calc() {
    for (int i=0; i < N; i++) {
        for (int j=0; j < 1e5; j++) {
            dp[i][j] = NINF;
        }
    }
}


void solve () {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> arr;
    int F = 0;
    for (int i=0; i < n; i++) {
        int a, b; cin >> a >> b;
        F += b;
        arr.push_back({a, b});
    }

    dp[0][0] = 0;
    for (int i=1; i <= n; i++) {
        int c = arr[i - 1].first;
        int f = arr[i - 1].second;

        for (int j=0; j <= F; j++) {
            if (j >= f && dp[i - 1][j - f] >= c) dp[i][j] = max(dp[i - 1][j] + x, dp[i - 1][j - f] + (x - c));
            else dp[i][j] = dp[i - 1][j] + x;
        }
    }

    int resp = 0;
    for (int i=0; i <= F; i++) {
        if (dp[n][i] >= 0) resp = i;
    }

    for (int i=0; i <= n; i++) {
        for (int j=0; j<=F; j++) dp[i][j] = NINF;
    }

    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    calc();
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
