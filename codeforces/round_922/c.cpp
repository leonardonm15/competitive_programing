#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int a, b, c; cin >> a >> b >> c;

    if (b > a) swap(b, a);
    int x = 0;
    bool flag = false;

    for (int i=60 - 1; i >= 0; i--) {
        int k = (1ll << i);
        if (!flag && (b & k) != (a & k)) {
            flag = true;
            continue;
        }
        if ((!(b & k) && (a & k)) && x + k <= c) {
            x += k;
        }
    }

    cout << (a ^ x) - (b ^ x) << endl;
    /* cout << abs(b - a) << endl; */
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
