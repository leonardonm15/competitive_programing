#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    int c = (n / 2);
    if (c&1) c++;
    
    if (n == 1 && k == 1) {
        cout << 1 << endl;
        return;
    }


    if (k <= c) {
        int v = k * 2;
        if (v % 2 == 0) v--;
        cout << v << endl;
    } else {

        int z = 1;

        while (k > c) {
            k -= c;
            z *= 2;
        }
        
        while (k >= c/2) {
            z  *= 2;
        }

        cout << k * z << endl;
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
