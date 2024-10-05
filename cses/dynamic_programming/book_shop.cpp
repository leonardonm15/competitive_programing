#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
// #define int long long

const int N = 1e3 + 5;
const int X = 1e5 + 5;

int dp[N][X];

void solve () {
    int n, k; cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) {
        int preço = h[i - 1];
        int paginas = s[i - 1];
        for (int j = 0; j <= k; j++) {
            if (preço > j) { dp[i][j] = dp[i - 1][j]; }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - preço] + paginas);
            }
        }
    }

    cout << dp[n][k] << endl;
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
