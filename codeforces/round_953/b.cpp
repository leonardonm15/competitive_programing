#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, a, b; cin >> n >> a >> b;
    int base = a * n;

    if (b < a) {
        cout << base << endl;
        return;
    }

    int l = 1;
    int r = min(n, b);
    int resp = base;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, resp)) {
            // pega esse k chutado, faz a soma até ele e soma

        } else {
        }
    }
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
