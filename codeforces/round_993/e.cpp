#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int INF = 1e18;

void solve () {
    int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;

    int resp = 0;
    for (int kn = 1; kn * l1 <= r2; kn *= k) {
        int lx = l1;
        int rx = r1;
        int ans = -1;

        // menor x no menor Y
        while (lx <= rx) {
            int x = (lx + rx) >> 1;
            if (kn * x >= l2) {
                ans = x;
                rx = x - 1;
            } else {
                lx = x + 1;
            }
        }

        // maior x no maior Y
        lx = l1;
        rx = r1;
        int ans2 = -1;
        while (lx <= rx) {
            int x = (lx + rx) >> 1;
            if (kn * x <= r2) {
                ans2 = x;
                lx = x + 1;
            } else {
                rx = x - 1;
            }
        }

        if (ans == -1 || ans2 == -1) continue;
        resp += ans2 - (ans - 1);

        /* cout << "------------------" << endl; */
        /* cout << "kn -> " << kn << endl; */
        /* cout << ans << " - " << ans2 << endl; */
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
