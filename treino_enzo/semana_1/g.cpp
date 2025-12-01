#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
const int K = 100 + 5;

int dp[N][K][2];

int n;
int calc(int i, int k) {
    if (i == n + 1) return 0;

    dp[i][k] = dp

}

void solve () {
    int k; cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    // maior soma que termina em mim em que eu me inverto
    // maior soma que termina em mim em que eu nao me inverto

    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][k][0] = max({
                    dp[i][k][0],
                    dp[i - 1][k][0] + arr[i - 1],
                    dp[i - 1][k][1] + arr[i - 1],
                    arr[i - 1],
                    });

            dp[i][k][1] = max({
                    dp[i - 1][k - 1][0] - arr[i - 1],
                    dp[i - 1][k][1] - arr[i - 1],
                    });
        }
    }

    int resp = -1;
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            resp = max({resp, dp[i][k][0], dp[i][k][1]});
        }
    }

    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
