#include <bits/stdc++.h>

using namespace std;
#define int long long

int maxw = 1e9 + 1;
int maxn = 105;

vector<vector<int>> dp(maxn, vector<int>(maxw)); // indexado em 1
vector<int> pesos(maxn);
vector<int> vals(maxn);

void solve () {
    int n, w; cin >> n >> w;
    for (int i=0; i < n; i++) cin >> pesos[i] >> vals[i];
    for (int i=1; i <= n; i++) {
        int val = vals[i - 1];
        int peso = pesos[i - 1];
        for (int k=1; k <= w; k++) {
            int last = dp[i-1][k];
            /* cout << last << endl; */
            if (k >= peso && val + dp[i - 1][k - peso] > dp[i-1][k]) dp[i][k] = val + dp[i - 1][k - peso];
            else dp[i][k] = dp[i-1][k];
        }
    }
    /* for (int i=0; i<=n; i++) { */
    /*     for (int j=0; j <= w; j++) { */
    /*         cout << dp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    cout << dp[n][w] << endl;
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
