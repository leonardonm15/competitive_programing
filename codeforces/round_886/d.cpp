#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    int resp = 0;
    int s = 0;
    for (int i=0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i=0; i < n; i++) {
        if (i == n - 1) {
            s++;
            resp = max(resp, s);
            break;
        }
        s++;
        if (arr[i + 1] - arr[i] > k) {
            resp = max(resp, s);
            s = 0;
        }
    }
    // cout << resp << endl;
    cout << n - resp << endl;
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
