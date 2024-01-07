#include <bits/stdc++.h>

using namespace std;
// #define int long long

void solve () {
    int n, k; cin >> n >> k;
    k = min(k, 30);
    cout << min(n, (1 << k) - 1) + 1 << endl;
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
