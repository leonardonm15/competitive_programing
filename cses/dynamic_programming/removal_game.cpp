#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 5000 + 5;
const int INF = -1e18;

int dp[N][N];
int arr[N];

int calc(int vez, int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != INF) return dp[l][r];

    return dp[l][r] = max({
            dp[l][r], 
            min(
                calc(vez ^ 1, l + 2, r) + arr[l],
                calc(vez ^ 1, l + 1, r - 1) + arr[l]
            ),
            min(
                calc(vez ^ 1, l + 1, r - 1) + arr[r],
                calc(vez ^ 1, l, r - 2) + arr[r]
               ),
        });
}

void solve () {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dp[i][j] = arr[i];
            else dp[i][j] = INF;
        }
    }

    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < n; j++) { */
    /*         dp[0][i][j] = -1; */
    /*         dp[1][i][j] = -1; */
    /*     } */
    /* } */

    cout << calc(0, 0, n - 1) << endl;

    /* cout << "------------------" << endl; */
    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < n; j++) { */
    /*         if (dp[i][j] == INF) cout << "- "; */
    /*         else cout << dp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
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
