#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 

const int N = 505;
const int INF = 1e9;
int dp[N][N];

int calc(int a, int b) {
    if (dp[a][b] != INF) return dp[a][b];

    for (int i = 1; i <= a / 2; i++) {
        dp[a][b] = min(dp[a][b], calc(i, b) + calc(a - i, b) + 1);
    }

    for (int i = 1; i <= b / 2; i++) {
        dp[a][b] = min(dp[a][b], calc(a, i) + calc(a, b - i) + 1);
    }

    return dp[a][b];
}

void solve () {
    int n, m; cin >> n >> m;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }

    cout << calc(n, m) << endl;
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
