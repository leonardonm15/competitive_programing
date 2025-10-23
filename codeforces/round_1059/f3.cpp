#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


bool check(pair<int, int>& a, pair<int, int>& b) {
    return abs(a.first - a.second) > abs(b.first - b.second);
}


void solve () {
    int n, m; cin >> n >> m;

    vector<pair<int, int>> ranges(m);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        ranges[i] = {l, r};
    }

    sort(ranges.begin(), ranges.end(), check);

    cout << "ranges  ----------------" << endl;
    for (auto [l, r]: ranges) {
        cout << l << " " << r << endl;
    }
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
