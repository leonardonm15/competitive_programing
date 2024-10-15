#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int MOD = 1e9 + 7;
int n, m;

vector<int> arr;
vector<vector<int>> dp;

int calc(int u, int i, int n) {
    if (i < n && arr[i] > 0 && u != arr[i]) return dp[i][u] = 0;
    if (i >= n - 1) return dp[i][u] = 1;
    if (dp[i][u] != -1) return dp[i][u];

    int resp = 0;
    for (int k = -1; k <= 1; k++) {
        if (u + k > 0 && u + k <= m) {
            resp += calc(u + k, i + 1, n);
            resp %= MOD;
        }
    }

    return dp[i][u] = resp;
}

void solve () {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }

    dp.resize(n + 2, vector<int>(m + 1, -1));

    int resp = 0;
    for (int u = 1; u <= m; u++) {
        resp += calc(u, 0, n);
        resp %= MOD;
    }

    cout << resp << endl;
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
