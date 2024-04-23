#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
vector<vector<int>> dp(1000 + 4, vector<int>(1000 + 4, -1));
vector<string> grid;
const int MOD = 1e9 + 7;

int calc(int i, int j) {
    if (grid[i][j] == '*') return 0;
    if (dp[i][j] > -1) return dp[i][j];
    dp[i][j] = calc(i - 1, j) + calc(i, j - 1);
    dp[i][j] %= MOD;
    return dp[i][j];
}

void solve () {
    int n; cin >> n;
    string bloq;
    for (int i=0; i < n + 2; i++) bloq += "*";
    grid.push_back(bloq);
    for (int i=0; i < n; i++) {
        string p, k;
        p += "*";
        cin >> k;
        p += k;
        p += "*";
        grid.push_back(p);
    }
    grid.push_back(bloq);

    if (grid[1][1] == '.') dp[1][1] = 1;
    else dp[1][1] = 0;
    cout << calc(n, n) << endl;
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
