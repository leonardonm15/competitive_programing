#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
 
void solve () {
    int n; cin >> n;
    if (n&1) {
        cout << "NO" << endl;
    } else {
        string s;
        cout << "YES" << endl;
        for (int i=0; i < n/2; i++) {
            s.push_back('A');
            s.push_back('A');
            s.push_back('B');
        }
        /* if (n&1) s.push_back('B'); */
        cout << s << endl;
    }
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
