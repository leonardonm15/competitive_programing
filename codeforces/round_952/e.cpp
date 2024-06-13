#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int a, b, c, q; cin >> a >> b >> c >> q;
    cout << a << " " << b << " " << c << endl;

    int resp = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                int sum = 0;
                if ((i * j * k) == q) {
                    /* int u = (a + (i - 1)) / i; */
                    /* int v = (b + (j - 1)) / j; */
                    /* int w = (c + (k - 1)) / k; */
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
