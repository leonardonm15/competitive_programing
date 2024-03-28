#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;

    while (n >= 1) {
        /* cout << "n -> " << n << endl; */
        set<int> fat;
        for (int i=2; i * i <= n; i++) {
            if (n % i == 0) {
                fat.emplace(i);
            }
        }

        // ve se meu cara atual é primo
        string r = to_string(n);
        bool flag3 = true;
        for (auto c: r) {
            if (c != '0' && c != '1') {
                flag3 = false;
            }
        }
        if (flag3) {
            cout << "YES" << endl;
            return;
        }

        int z = n;

        for (int cara: fat) {
            string r = to_string(cara);
            bool flag = true;
            for (auto c: r) {
                if (c != '0' && c != '1') {
                    flag = false;
                }
            }
            if (flag) {
                n /= cara;
            }
        }

        if (z == n) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
