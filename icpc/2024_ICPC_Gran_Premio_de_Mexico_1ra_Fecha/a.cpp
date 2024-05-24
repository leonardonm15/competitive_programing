#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int dp[N][N];

void calc(int n) {
    for (int i=1; i <= n; i++) {
        int m = 1e9;
        for (int j=i + 1; j <= n; j++) {
            if (i > 1) m = min(abs(dp[0][i] - dp[0][j]), dp[i - 1][j]);
            else m = min(m, abs(dp[0][i] - dp[0][j]));
            dp[i][j] = m;
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    int n; cin >> n;
    for (int i=1; i <= n; i++) cin >> dp[0][i];
    calc(n);
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << dp[l][r] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();

}
