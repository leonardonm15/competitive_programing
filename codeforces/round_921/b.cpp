#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int x, n; cin >> x >> n;
    int resp = 0;

    for (int i=1; i * i <= x; i++) {
        if (x % i > 0) continue;
        if (x / i >= n) resp = max(resp, i);
        if ((x / (x / i)) >= n) resp = max(resp, x / i);
    }

    cout << resp << endl;
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
