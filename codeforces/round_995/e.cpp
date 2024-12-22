#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>

const int N = 2e5 + 5;

vector<vector<int>> dp(N, vector<int>(3, -1));
vector<int> a(N);
vector<int> b(N);

int resp = 0;

int calc(int u, int val, int vp, int ks, int n, int k) {
    if (ks > k) return -1;
    if (u > n) return val;

    if (dp[u][vp] != -1) return dp[u][vp];
    
    int v1 = calc(u + 1, val + a[u + 1], 0, ks    , n, k);
    int v2 = calc(u + 1, val + b[u + 1], 1, ks + n, n, k);
    int v3 = calc(u + 2, val           , 2, ks    , n, k);

    return dp[u][vp] = max({v1, v2, v3});
}

void solve () {
    int n, k; cin >> n >> k;


    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    cout << calc(0, 0, 0, 0, n, k) << endl;

    for (int i = 0; i <= n; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
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
