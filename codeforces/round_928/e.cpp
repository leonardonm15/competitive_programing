#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;

    int c = 1;
    while (true) {
        int t = (n + 1) / 2;
        if (k <= t) {
            cout << (2 * k - 1) * c << endl;
            return;
        }
        k -= t;
        n /= 2;
        c *= 2;
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
