#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    int resp = 0;
    int ans = 0;

    for (int i=n - 1; i >= 1; i--) {
        if ((i + gcd(i, n)) >= resp) {
            ans = i;
            resp = i + gcd(i, n);
        }
    }

    cout << ans << endl;
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
