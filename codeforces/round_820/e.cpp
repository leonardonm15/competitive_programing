#include <bits/stdc++.h>
 
using namespace std;
 
/* #define endl '\n' */ 
#define int long long
 
// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
 
void solve () {
    int a, b;
    map<int, int> map;
    for (int i=2; i <= 26; i++) {
        cout << "? " << 3 << " " << i << endl;
        cin >> a;
        cout << "? " << i << " " << 3 << endl;
        cin >> b;
        if (a == -1) {
            cout << "! " << i - 1 << endl;
        } else if (a != b) {
            cout << "! " << a + b << endl;
        }
    }
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
