#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
//

int bpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b&1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve () {
    int n; cin >> n;
    int k = 0;
    int c = 1;
    while (k < n) {
        k = bpow(c, c);
        c++;
    }
    c--;
    if (k == n) cout << c << endl;
    else cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
