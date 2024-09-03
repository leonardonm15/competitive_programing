#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int p = 0;
    int seq = 0;
    for (int i = 1; i <= n; i++) {
        p++;
        if (i == n || arr[i] - arr[i - 1] > k) {
            seq = max(seq, p);
            p = 0;
        }
    }

    cout << n - seq << endl;
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
