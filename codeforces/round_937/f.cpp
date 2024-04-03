#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
 
void solve () {
    int a, b, c; cin >> a >> b >> c;
    int h = 0;

    if ((b > 0 && c == 0) || c <= a || c == 0) {
        cout << - 1 << endl;
        return;
    }
 
    if (c > 0) {
        h += (b / c);
        h += b % c ? 1 : 0;
    }
 
    if (a > 0 && c >= 2) {
        if (c&1) {
            if (b > 0 && ((b%c) == c - 1 || b%c == 0)) h++;
            c--;
            a--;
        }
    }
 
    while (c > 1) {
        a -= c / 2;
        c >>= 1;
        h++;
    }
 
    if (a == 0) cout << h << endl;
    else cout << - 1 << endl;
 
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
