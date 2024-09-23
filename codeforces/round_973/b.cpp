#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];

    
    for (int i = n - 3; i >= 0; i--) {
        arr[n - 2] -= arr[i];
    }

    cout << arr[n - 1] - arr[n - 2] << endl;

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
