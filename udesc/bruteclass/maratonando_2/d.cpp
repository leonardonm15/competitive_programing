#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, h; cin >> n >> h;
    vector<int> arr(n);
    int resp = 0;
    for (int i=0; i < n; i++) cin >> arr[i];

    int l = 1;
    int r = 1e18;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int resp = 0;
        for (int i=0; i < n; i++) {
            if (i == n - 1) {
                resp += mid;
                break;
            }
            resp += min(mid, arr[i + 1] - arr[i]);
        }

        if (resp >= h) {
            ans = mid;
            r = mid - 1;
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
