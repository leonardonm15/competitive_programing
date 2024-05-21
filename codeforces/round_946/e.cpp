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
    
void solve () {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> op(50 + 5);
    op[0] = {0, 0};
    for (int i=1; i <= n; i++) {
        int a, b; cin >> a >> b; // custo felicidade
        op[i] = {a, b};
    }
    
    map<int, int> dp;
    dp[0] = 0;
    for (int i=1; i <= n; i++) {
        // minha felicidade que eu ganho =0; :( :3 :D ;_; ;-; '-' :) :c >:(
        if (op[
        op[i] = max(op[
    }

    /* dado um mes x qual a melhor felicidade que eu consigo */
    
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
