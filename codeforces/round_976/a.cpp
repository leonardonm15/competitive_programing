#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    int resp = 0;

    if (k == 1) {
        cout << n << endl;
        return;
    }

    int mx = 1;

    while (mx < n) mx *= k;

    while (n > 0) {
        while (mx > n) {
            mx /= k;
            mx = max(mx, 1ll);
        }

        int c = n / mx;

        n -= c * mx;
        resp += c;
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
