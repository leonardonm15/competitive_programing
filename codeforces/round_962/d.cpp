#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int eq (int a, int b, int c) {
    return ((a * b) + (a * c) + (b * c));
}

void solve () {
    int n, x; cin >> n >> x;

    int resp = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b * a <= n; b++) {
            int c = x - (a + b);
            if (c <= 0) continue;
            
            int l = 1;
            int r = c;
            int ans = 0;

            while (l <= r) {
                int mid = (l + r) >> 1;
                int val = eq(a, b, mid);
                if (val <= n) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            resp += ans;
        }
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
