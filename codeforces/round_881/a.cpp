#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int m; cin >> m;
    vector<int> arr(m);
    int n = arr.size();
    for (int i=0; i < m; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (n == 1) {
        cout << 0 << endl;
        return;
    } else if (n == 2 || n == 3) {
        cout << arr[n - 1] - arr[0] << endl;
        return;
    } else {
        int resp = 0;
        n--;
        for (int i=0; i <= n/2; i++) {
            /* cout << "arr[n - i] -> " << arr[n - i] << endl; */
            /* cout << "arr[i] -> " << arr[i] << endl; */
            resp += arr[n - i] - arr[i];
        }
        cout << resp << endl;
    }
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
