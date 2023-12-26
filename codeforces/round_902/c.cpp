#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, m, k; cin >> n >> m >> k;
    if (k > 3) {
        cout << 0 << endl;
        return;
    }

    if (k == 1) {
        cout << 1 << endl;
        return;
    }

    if (k == 2 && m <= n) {
        cout << m << endl;
        return;
    }

    if (k == 2 && m > n) {
        cout << n + ((m - n) / n) << endl;
        return;
    }

    if (k == 3 && m <= n) {
        cout << 0 << endl;
        return;
    }

    if (k == 3 && m > n) {
        cout << (m - n) - ((m - n) / n) << endl;
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) {
            solve();
        }
    } else {
        solve();
    }
    return 0;
}
