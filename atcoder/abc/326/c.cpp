#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int c = 0;
    int l = 0;
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && arr[r] - arr[l] < k) r++;
        c = max(c, r - l);
    }
    cout << c << endl;
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
