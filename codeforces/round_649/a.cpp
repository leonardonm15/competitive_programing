#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    int u = -1, v = -1;
    int ans = -1, sum = 0;

    for (int i=0; i < n; i++) {
        sum = (sum + arr[i]) % k;
        if (sum) ans = max(ans, i + 1);
        if (u != -1 && sum != u) ans = max(ans, i + 1 - v);
        if (u == -1 && sum) {
            u = sum;
            v = i + 1;
        }
    }

    cout << ans << endl;
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
