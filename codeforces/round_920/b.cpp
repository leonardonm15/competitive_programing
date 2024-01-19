#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    int k = 0;
    int resp = 0;
    for (int i=0; i < n; i++) {
        if (s[i] == '0' && t[i] == '1') {
            k--;
            resp++;
        }
        if (s[i] == '1' && t[i] == '0') {
            k++;
            resp++;
        }
    }
    k = abs(k);
    resp += k;

    cout << resp / 2 << endl;
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
