#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int a, b, c; cin >> a >> b >> c;
    int pulo = abs(a - b);
    int maximo = 1 + pulo;
    int minimo = 1;
    
    // c + pulo for a ou b ta zoado
    
    if (c + pulo == a || c + pulo == b) {`
        cout << -1 << endl;
        return;
    }

    while (minimo != maximo) {
        if (minimo == a || minimo == b ) {
            minimo++;
            continue;
        }
        if (minimo == c) {
            cout << minimo + pulo << endl;
            return;
        } else if (minimo + pulo == c) {
            cout << minimo << endl;
            return;
        }
        minimo++;
    }
    cout << -1 << endl;
    return;
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
