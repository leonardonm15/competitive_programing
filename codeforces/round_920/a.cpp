#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     



void solve () {
    int n;
    /* int resp = 1e5; */
    int a, b; cin >> a >> b;
    long long resp = 1e6;

    for (int i=0; i < 3; i++) {
        int x, y; cin >> x >> y;
        if (x == a) resp = abs(min(b, y) - max(b, y));
    }

    cout << resp * resp << endl;
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
