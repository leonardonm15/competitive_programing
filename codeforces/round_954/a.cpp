#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    vector<int> arr(3); cin >> arr[0] >> arr[1] >> arr[2];

    int resp = 1e9 + 5;
    for (int i = 0; i < 3; i++) {
        int k = 0;
        for (int j = 0; j < 3; j++) {
            k += abs(arr[i] - arr[j]);
        }
        resp = min(resp, k);
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
