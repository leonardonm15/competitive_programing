#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int resp = 1e9 + 5;
    for (int o = 0; o <= 2; o++) {
        for (int t = 0; t <= 1; t++) {
            for (int s = 0; s <= 4; s++) {
                for (int d = 0; d <= 2; d++) {
                    int k = o + 3*t + 6*s + 10*d;
                    if (k <= n && (n - k) % 15 == 0) {
                        resp = min(resp, o + t + s + d + (n - k) / 15);
                    }
                }
            }
        }
    }

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
