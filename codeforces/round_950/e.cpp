#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m; cin >> n >> m;
    vector<vector<tuple<int, int, int>>> a(n);
    vector<vector<tuple<int, int, int>>> b(n);

    for (int i = 0; i < n; i++) {
        vector<tuple<int, int, int>> c;
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            c.push_back({num, i, j});
        }
        a[i] = c;
    }

    int row = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto [x, y, z] = a[i][j];
            if (x == 1) {
                row = i;
                sort(a[i].begin(), a[i].end());
            }
        }
    }


    cout << (row&1 ? "YES" : "NO") << endl;
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
