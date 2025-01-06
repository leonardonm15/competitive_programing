#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, q; cin >> n >> q;

    vector<vector<int>> arr(n, vector<int>(n));
    vector<vector<int>> rec(n, vector<int>(n));

    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            k *= arr[i][j];
        }
    }

    int mult = 1;
    for (int i = 0; i < n; i++) {
        mult *= arr[0][i];
        rec[0][i] = mult;
    }

    for (int i = 1; i < n; i++) {
        int mult = 1;
        for (int j = 0; j < n; j++) {
            mult *= arr[i][j];
            rec[i][j] = rec[i - 1][j] * mult;
        }
    }

    while (q--) {
        int xr, xl, yl, yr; cin >> xr >> xl >> yl >> yr;
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
