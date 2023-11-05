
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
 
void solve () {
    int n; cin >> n;
    string s; cin >> s;
    int mp = 1;
    int p = 1;
    for (int i=0; i < n; i++) {
        if (s[i] != s[i + 1]){
            p = 1;
        } else p++;
        mp = max(mp, p);
    }
    cout << mp + 1 << endl;
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
