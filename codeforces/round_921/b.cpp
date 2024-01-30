#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int x, n; cin >> x >> n;
    while (x > 0) {
        cout << "---------------" << endl;
        int q = x / n;
        q += x % n;
        int k = x / q;
        cout << "n -> " << n << endl;
        cout << "q -> " << q << endl;
        cout << "k -> " << k << endl;
        n -= k;
        x -= k * q;
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
