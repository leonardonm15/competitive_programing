#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, k, q; cin >> n >> k >> q;
    int resp = 0;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    for (int i=0; i < n; i++) {
        int cnt = 0;
        while (i < n && arr[i] <= q) {
            cnt++;
            i++;
        }

        if (cnt >= k) {
            if (cnt - k > 0) {
                resp += (cnt - k) + 1;
                resp++;
                resp += ((0 + ((cnt - k))) * cnt) / 2;
            }
            else resp++;
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
