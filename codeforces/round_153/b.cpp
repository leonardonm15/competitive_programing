#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int m, k, a, b; cin >> m >> k >> a >> b;

    int mk = m % k;
    int resp = max(0ll, mk - a);
    a = max(0ll, a - mk);
    b += a / k;
    
    m -= mk;
    int c = m / k;
    resp += max(0ll, c - b);

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
