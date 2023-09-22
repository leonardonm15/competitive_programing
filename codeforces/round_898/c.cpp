#include <bits/stdc++.h>

using namespace std;
//#define int long long


void solve () {
    vector<vector<int>> arr;
    arr = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3 ,4, 5, 5, 4, 3, 2 ,1},
        {1, 2, 3 ,4, 5, 5, 4, 3, 2 ,1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    int resp = 0;
    for (int i=0; i < 10; i++) {
        for (int j=0; j < 10; j++) {
            char c; cin >> c;
            if (c == 'X') {
                resp += arr[i][j];
            }
        }
    }
    cout << resp << endl;
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
