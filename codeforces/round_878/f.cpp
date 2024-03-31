#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int a, b, c; cin >> a >> b >> c;
    int h = 0;
    int extra = 0;
    if (c == 0 && (a > 0 || b > 0)) {
        cout << -1 << endl;
        return;
    }

    h += (b / c) + (b % c);
    if (c&1) {
        if (b%c == 0) h++;
        a--;
        c--;
    }
    /* cout << "H -> " << h << endl; */
    /* cout << a << " " << b << " " << c << endl; */

    while (c > 1) {
        a -= (c / 2);
        c >>= 1;
        h++;
    }
    /* cout << a << " " << b << " " << c << endl; */
    if (a == 0) cout << h << endl;
    else cout << -1 << endl;

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
