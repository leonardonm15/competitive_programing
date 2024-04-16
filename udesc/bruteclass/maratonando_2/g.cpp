#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s; cin >> s;
    if ((int)s.size()&1) cout << "NO" << endl;
    else {
        int k = s.size() / 2;
        for (int i=0; i < (int)s.size()/2; i++) {
            if (s[i] != s[i + k]) {
                cout << "NO" << endl;
                return;
            }
        }

        cout << "YES" << endl;
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
