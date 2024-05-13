#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i].first;
    for (int i=0; i < n; i++) cin >> arr[i].second;

    sort(arr.begin(), arr.end());

    int i = 0;
    int resp = 0;
    bool flag = false;
    for (int i=0; i < n; i++) {
        if (k - arr[i].first >= 0) {
            if (arr[i].second && flag) continue;
            k -= arr[i].first;
            resp++;
        }

        if (arr[i].second) flag = true;
    }

    cout << resp << endl;
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
