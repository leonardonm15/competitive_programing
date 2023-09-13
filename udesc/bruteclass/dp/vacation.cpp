#include <bits/stdc++.h>

using namespace std;
//#define int long long
vector<vector<int>> arr(1e5, vector<int> (3));
vector<vector<int>> dp(1e5, vector<int>(3, -1));

int f(int x, int y) {
    if (x == 0) return arr[0][y];
    if (dp[x][y] == -1) {
        int index1 = (y + 1) % 3;
        int index2 = (y + 3 - 1) % 3;
        int step1 = f(x-1, index1) + arr[x][y];
        int step2 = f(x-1, index2) + arr[x][y];
        dp[x][y] = max(step1, step2);
    }
    return dp[x][y];
}

void solve () {
    int n; cin >> n;
    for (int i=0; i < n; i++) {
        for (int k=0; k < 3; k++) {
            cin >> arr[i][k];
        }
    }

    cout << max({f(n-1, 0), f(n-1, 1), f(n-1, 2)}) << endl;
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
