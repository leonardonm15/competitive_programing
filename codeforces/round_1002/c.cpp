#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];

    vector<int> mex(304);
    vector<int> col;

    for (int i = 0; i < n; i++) {
        int j = n - 1;
        int k = 0;
        while (j >= 0 && arr[i][j] == 1) {
            j--;
            k++;
        }

        col.push_back(k);
    }

    sort(col.begin(), col.end());

    for (auto c: col) {
        for (int i = 0; i <= c; i++) {
            if (!mex[i]) {
                mex[i]++;
                break;
            }
        }
    }

    for (int i = 0; i < 304; i++) {
        if (!mex[i]) {
            cout << i << endl;
            return;
        }
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
