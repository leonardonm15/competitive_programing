#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int N = 1e8;
vector<pair<int, int>> arr;
vector<int> dp(N, -1e18);

void solve () {
    int n, k, x; cin >> n >> k >> x;
    for (int i=0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }

    dp[0] = 0;
    for (int i=0; i < n; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i] - arr[i].first + arr[i].second);
        dp[min(n, i + k)] = max(dp[min(n, i + k)], dp[i] - x);
    }

    cout << max(0ll, dp[n]) << endl;
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
