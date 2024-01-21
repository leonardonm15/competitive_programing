#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int h, w, x, y, a, b; cin >> h >> w >> y >> x >> b >> a;
    
    int dv = y - b;
    int dh = abs(a - x);

    /* cout << "dh -> " << dh << endl; */
    /* cout << "dv -> " << dv << endl; */

    if (dv >= 0 && dh <= dv && dv % 2 == 1) {
        cout << "ALICE" << endl;
    } else if (dv >= 0 && dh <= dv && dv % 2 == 0) {
        cout << "BOB" << endl;
    } else {
        cout << "DRAW" << endl;
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
