#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int a, b, c, q; cin >> a >> b >> c >> q;
    int resp = 0;
    int vol = a * b * c;

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            int k = q / (i * j);
            if ((i * j * k) == q && k <= c) {
                /* cout << "--------------" << endl; */
                // cout << "ijk -> " << i * j * k << endl;
                int uai = ((a - i) + 1) * ((b - j) + 1) * ((c - k) + 1);
                resp = max(resp, uai);
                // cout << i << " " << j << " " << k << endl;
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
