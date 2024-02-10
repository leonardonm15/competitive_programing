#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int mod = 1e9 + 7;

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int p(int u) {
    int c = 1;
    for (int i=0; i < u; i++) {
        c *= 2;
        c %= mod;
    }
    return c;
}

void solve () {
    int n; cin >> n;
    int k = p(n - 2);
    cout << (((n * k) % mod) * ((mod + 1) / 2)) % mod << endl;
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
