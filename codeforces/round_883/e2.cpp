#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    for (int i=2; i < 63; i++) {
        int l, r, mid, res2, lv;
        res2 = -1;
        l = 2;
        r = 1e9;
        lv = 0;
        while (l <= r) {
            int res = 1;
            bool dm = false;
            mid = (l + r) / 2;
            int cm = mid;
            for (int k=1; k <= i; k++) {
                res = res + cm; 
                if (k < i) {
                    if ((1e18 - res)/mid < cm) {
                        dm = true;
                        break;
                    }
                    cm *= mid;
                }
            } 
            /* cout << "mid  - " << mid << " i - " << i << endl; */
            /* cout << "resultado -> " << res << endl; */
            if (res > n || dm) {
                r = mid - 1;

            } else {
                lv = mid;
                res2 = res;
                l = mid + 1;
            }
            /* cout << l << " " << r << endl; */
        }
        if (res2 == n) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
