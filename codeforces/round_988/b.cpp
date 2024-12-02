#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++) {
        int l = i + 1;
        int r = arr.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            int v = arr[mid] * arr[i];
            if (v < n - 2) {
                l = mid + 1;
            } else if (v > n - 2) {
                r = mid - 1;
            } else {
                cout << arr[i] << " " << arr[mid] << endl;
                return;
            }
        }
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
