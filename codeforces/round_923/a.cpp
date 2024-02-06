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
    int c = -1;
    int f = -1;

    for (int i=0; i < n; i++) {
        if (s[i] == 'B') {
            c = i;
            break;
        }
    }

    for (int i=n - 1; i >= 0; i--){
        if (s[i] == 'B') {
            f = i;
            break;
        }
    }

    if (c == -1) cout << 0 << endl;
    else {
        cout << (f - c) + 1<< endl;
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
