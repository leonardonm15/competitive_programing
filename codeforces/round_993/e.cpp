#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    // 2 1 2 2 2
    //
    // 2 / 1 
    // 2 / 2
    // k * n = y

    int resp = 0;
    for (int i = 1; i <= r2; i *= k) {
        int l = l1;
        int r = r1;
        int ans1 = 0;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid * i <= r2) {
                ans1 = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        l = l1;
        r = r2;
        int ans2 = 0;

        resp += ans;
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
