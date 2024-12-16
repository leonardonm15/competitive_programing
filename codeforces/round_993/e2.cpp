#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;

    int resp = 0;
    for (int kn = 1; kn <= r2; kn *= k) {
        int l = l1;
        int r = r1;
        int ans = 0;

        while (l <= r) {
            int x = (l + r) >> 1;
            if (x * kn <= r2) { // maior x que nao estoura o Y e é maior que l2
                if (x * kn >= l2) ans = x;
                l = x + 1;
            } else {
                r = x - 1;
            }
        }

        l = l1;
        r = l2;
        int ans2 = 0;
        while (l <= r) {
            int x = (l + r) >> 1;
            if (x * kn >= l2) {
                if (x * kn <= r2) ans2 = x;
                l -= 1;
            } else r += 1;
        }

        resp += ans - ans2;
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
