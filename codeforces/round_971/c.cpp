#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int x, y, k; cin >> x >> y >> k;

    int p1 = (((x/k) + (x%k > 0 ? 1 : 0)) * 2) - 1;
    int p2 = ((y/k) + (y%k > 0 ? 1 : 0)) * 2;

    cout << max(p1, p2) << endl;
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
