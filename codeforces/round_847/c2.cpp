#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n + 1));
    for (int i=0; i < n; i++) {
        for (int j=0; j < n - 1; j++) {
            cin >> arr[i][j];
        }
    }
    vector<int> f(n + 100);
    vector<pair<int, int>> c(n, pair<int, int>{-1, -1});
    for (int i=0; i < n; i++) {
        f[arr[i][0]]++;
        if (arr[i][0] == 1) c.push_back({i, arr[i][0]});
    }
    int idx;
    sort(c.rbegin(), c.rend());
    if (f[c[0].second] > f[c[1].second]) {
        cout << c[0].second << " ";
        idx = c[0].first;
    } else {
        cout << c[1].second << " ";
        idx = c[1].first;
    }
    for (auto cara: arr[idx]) cout << cara << " ";
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
