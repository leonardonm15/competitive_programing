#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, m; cin >> n >> m;
    vector<int> p;
    int max_dist = -1;
    for (int i=0; i < m; i++)  {
        int num; cin >> num;
        p.push_back(num);
        if (i > 0 && i < m) {
            int dist = num - p[i - 1];
            if (dist&1) dist = (dist+1) / 2;
            else dist /= 2;
            if (dist > max_dist) max_dist = dist;
        }
    }
    int da = p[0];
    int db = n - p[m - 1];

    if (da > max_dist || db > max_dist) max_dist = max(da, db);
    cout << max_dist << endl;
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
