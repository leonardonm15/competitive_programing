#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<pair<int, int>> v(n);

    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i=0; i < n; i++) v[i] = {arr[i], i};

    sort(v.begin(), v.end());
    for (int i=0; i < n; i++) {
            /* cout << "v[i].first -> " << v[i].first << endl; */
            /* cout << "arr[v[i].second] - > " << arr[i] << endl; */
        if ((v[i].first & 1) != (arr[i] & 1)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
