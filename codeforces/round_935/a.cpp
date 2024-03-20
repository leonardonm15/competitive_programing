#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int a, b, c; cin >> a >> b >> c;
    int resp = 0;
    resp += a;
    int d = b % 3;
    if (d > 0 && 3 - d > c) {
        cout << -1 << endl;
        return;
    }
    resp += (b + c) / 3;
    if ((b + c) % 3 != 0) resp++;
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
