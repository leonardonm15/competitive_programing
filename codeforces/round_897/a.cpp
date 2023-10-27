#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<pair<int, int>> arr;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back({num, i});
    }
    sort(arr.rbegin(), arr.rend());
    vector<int> resp(n);
    for (int i=0; i < n; i++) {
        resp[arr[i].second] = i + 1;
    }
    for (auto i: resp) cout << i << " ";
    cout << endl;
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
