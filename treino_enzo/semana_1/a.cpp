#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int mx = arr[n - 1];

    /* cout << "arr -> "; */
    int b = 0;
    for (int i = n - 2; i >= 0; i -= 2) {
        int diff = arr[i + 1] - arr[i];

        if (k > 0 && diff) {
            arr[i] += min(diff, k);
            k -= (diff - (arr[i + 1] - arr[i]));
        }
        b += arr[i];
        /* cout << arr[i] << " "; */
    }
    /* cout << endl; */


    int a = 0;
    for (int i = n - 1; i >= 0; i -= 2) a += arr[i];

    cout <<  a - b << endl;
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
