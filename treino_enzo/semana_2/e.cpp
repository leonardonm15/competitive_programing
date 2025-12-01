#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e6 + 5;
const int MOD = 998244353;

int n, m;
int dp[N][2];

void solve () {
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    dp[0][1] = m;

    for (int i = 1; i <= n; i++) {
        int antes_qualquer_cara = dp[i - 1][0] * (m - 2);
        int antes_o_proibido = dp[i - 1][1] * (m - 1);
        dp[i][0] = (antes_qualquer_cara + antes_o_proibido) % MOD;
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n - 1][0] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
