#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int N = 1e6;
vector<pair<int, int>> arr;

void solve () {
    int n, k, x; cin >> n >> k >> x;
    vector<int> price(x);
    for (int i=0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }

    for (int i=1; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - k]);
    }
            


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
