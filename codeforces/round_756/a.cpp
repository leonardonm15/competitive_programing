#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s; cin >> s;
    int n = s.size();
    if ((s[n - 1] - '0') % 2 == 0) cout << 0 << endl;
    else if ((s[0] - '0') % 2 == 0) cout << 1 << endl;
    else {
        for (auto cara: s) {
            if ((cara - '0') % 2 == 0) {
                cout << 2 << endl;
                return;
            }
        }
        cout << -1 << endl;
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
