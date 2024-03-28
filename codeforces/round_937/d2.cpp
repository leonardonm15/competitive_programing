#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;

    while (n > 1) {
        string r = to_string(n);
        // vejo se meu cara atual é 01
        bool flag = true;
        for (auto c: r) {
            if (c != '0' && c != '1') {
                flag = false;
            }
        }
        if (flag) {
            cout << "YES" << endl;
            return;
        }

        bool is_primo = true;
        for (int i=2; i * i <= n; i++) {
            if (n % i == 0) {
                string s = to_string(i);
                bool flag2 = true;
                for (auto cara: s) {
                    if (cara != '0' && cara != '1') {
                        flag2 = false;
                    }
                }
                if (flag2) {
                    n /= i;
                    is_primo = false;
                    break;
                }
                else {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        if (is_primo) {
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
