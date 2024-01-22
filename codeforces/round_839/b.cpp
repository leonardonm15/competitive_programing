#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int a, b, d, c; cin >> a >> b >> d >> c;

    for (int i=0; i < 6; i++) {
        swap(a, b);
        swap(a, c);
        swap(d, a);
        /* cout << " ------------------- " << endl; */
        /* cout << a << " " << b << endl; */
        /* cout << d << " " << c << endl; */
        if (a < b && a < d && b < c && d < c) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
