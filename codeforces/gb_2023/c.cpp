#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    int soma = 0;
    int nimp = 0;
    int npar = 0;
    for (int i=0; i < n; i++) {
        int s; cin >> s;
        soma += s;
        if (s&1) nimp++;
        if (i == 0) {
            cout << s << " ";
            continue;
        }
        if (nimp >= 3) {
            int k = nimp;
            if (k % 3 == 0 || k % 3 == 2) {
                cout << soma - (nimp / 3) << " ";
            } else if (k % 3 == 1) {
                cout << soma - (nimp / 3) - 1 << " ";
            }
        } else {
            cout << soma - ((int) nimp&1) << " ";
        }
    }
    cout << endl;
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

