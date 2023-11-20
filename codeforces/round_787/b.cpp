#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int k = 0;
    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i = n - 2; i >= 0; i--) {
        while (arr[i] >= arr[i + 1] && arr[i] > 0) {
            arr[i] = arr[i] / 2;
            /* cout << arr[i] << " " << arr[i - 1] << endl; */
            k++;
        }
        if (arr[i] == arr[i + 1]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << k << endl;
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
