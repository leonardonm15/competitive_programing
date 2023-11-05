#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s; cin >> s;
    string p = "3141592653589793238462643383279502884197169399";
    for (int i=0; i < s.size(); i++) {
        if (s[i] != p[i]) {
            cout << i << endl;
            return;
        }
    }
    cout << s.size() << endl;
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
