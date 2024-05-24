#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int h = 0;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        h ^= arr[i];
    }
    sort(arr.begin(), arr.end());

    cout << "H -> " << h << endl;

    int d = 0;
    if (n > 1) for (int i=1; i < n; i++) {
        cout << "arr[i] - arr[i - 1] -> " << arr[i] - arr[i - 1] << endl;
        d ^= (arr[i] - arr[i - 1]);
    } else d = arr[0];

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
