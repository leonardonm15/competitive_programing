#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, c, k; cin >> n >> c >> k;
    /* if (k >= ((n / c) - 1)) */ 

    /* cout << "div -> " << (n / c) << endl; */
    if (k == n || n == 1 || c == 1 || k >= (n - ((n + 1) / c))) cout << "NO" << endl;
    else cout << "YES" << endl;
    // pinta quantos quiser 
    // pinta pouco mas
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
