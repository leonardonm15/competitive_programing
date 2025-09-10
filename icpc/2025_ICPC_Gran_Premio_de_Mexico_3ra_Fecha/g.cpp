#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define float long double

float bexp(float a, int k) {
    float resp = 1;
    while (k > 0) {
        if (k & 1) {
            resp *= a;
        }
        a *= a;
        k >>= 1;
    }

    return resp;
}

void solve () {
    int a, c, ba; cin >> a >> c >> ba;

    float h1 = a, h2 = c, b = ba;

    float br = (b - 1) / b;
    int l = 1;
    int r = 1e9;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        /* cout << "-----------------" << endl; */
        /* cout << "Mid -> " << mid << endl; */
        /* cout << "res -> " << bexp(br, mid) * h1 << endl; */

        if ((bexp(br, mid) * h1) <= h2) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
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
