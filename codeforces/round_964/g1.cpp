#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int l = 2, r = 999;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        cout << "? 2 " << mid << endl;
        int resp; cin >> resp;
        if (resp > 2 * mid) {
            ans = mid;
            r = mid - 1;
        } else {
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
