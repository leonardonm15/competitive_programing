#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int a, b, c; cin >> a >> b >> c;
    int d = c - b;
    if (a < abs(d) + (b + d)) cout << 1 << endl;
    else if (a > abs(d) + (b + d)) cout << 2 << endl;
    else cout << 3 << endl;
    /* cout << min(a, abs(b - c) + max(1, abs(abs(b - c) - 1))) << endl; */
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
