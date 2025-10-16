#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 4e3 + 5;
const int MOD = 998244353;

int dp[N]; // Jump by where i am

void solve () {
    int n, k; cin >> n >> k;

    dp[0] = 1;

    for (int jump = n; jump >= 1; jump--) {
        if (jump == k) continue;
        for (int i = 0; i <= n; i++) {
            if (i + jump <= n) {
                dp[i + jump] += dp[i];
                dp[i + jump] %= MOD;
            }

        }
    }


    cout << dp[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
