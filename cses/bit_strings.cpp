#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve () {
    int n; cin >> n;
    int resp = 1;
    for (int i=1; i <= n; i++) {
        resp = (resp * 2) % mod;
    }
    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
