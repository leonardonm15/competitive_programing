#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int gauss(int i, int f) {
    return ((i + f) * (f - i + 1)) / 2;
}

void solve () {
    int n, k; cin >> n >> k;

    int l = k;
    int r = n + k;
    int ans = 1e18;

    while (l <= r) {
        int mid = (l + r) >> 1;

        int lp = gauss(k, mid);
        int rp = gauss(mid + 1, n + k - 1);

        /* cout << "-----------------" << endl; */
        /* cout << "Mid -> " << mid << endl; */
        /* cout << "lp -> " << lp << endl; */
        /* cout << "rp -> " << rp << endl; */

        if (lp - rp < 0) {
            ans = mid;
            l = mid + 1;
        } else if (lp - rp > 0) {
            r = mid - 1;
        } else {
            ans = mid;
            break;
        }
    }


    /* cout << "gauss(6, 7) -> " << gauss(6, 7) << endl; */
    /* cout << "n + k -> " << n + k << endl; */
    int q1 = abs(gauss(k, ans) - gauss(ans + 1, n + k - 1));
    int q2 = abs(gauss(k, ans + 1) - gauss(ans + 2, n + k - 1));
    int q3 = abs(gauss(k, ans - 1) - gauss(ans, n + k - 1));

    /* cout << "----------------------" << endl; */
    /* cout << "ans -> " << ans << endl; */
    /* cout << "q1 -> " << q1 << endl; */
    /* cout << "q2 -> " << q2 << endl; */
    /* cout << "q3 -> " << q3 << endl; */
    
    cout << min({q1, q2, q3}) << endl;
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
