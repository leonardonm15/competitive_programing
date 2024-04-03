#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
void solve () {
    int a, b, c; cin >> a >> b >> c;

    if (a + 1 != c) {
        cout << - 1 << endl;
        return;
    }

    if (a + b + c == 1) {
        cout << 0 << endl;
        return;
    }

    int curr = 1, next = 0, res = 1;
    for (int i=0; i < a + b; i++) {
        if (!curr) {
            swap(next, curr);
            res++;
        }
        curr--;
        next++;
        if (i < a) {next++;}
    }

    cout << res << endl;
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
