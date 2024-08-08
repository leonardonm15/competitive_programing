#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int l = 2, r = 999;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        cout << "? " <<  mid << " " << r << endl;
        int resp; cin >> resp;
        if (resp == ((mid + 1) * (r + 1))) {
            ans = mid;
            r = mid - 1;
        } else if (resp == (mid * r)) {
            cout << "! " << ans << endl;
            return;
        } else {
            /* if (resp == (mid * (resp + 1))) { */
            l = mid + 1;
        }
    }

    cout << "! " << ans << endl;
}

signed main() {
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
