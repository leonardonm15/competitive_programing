#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


void solve () {
    int n, q, k; cin >> n >> q >> k;
    k--;
    int p = 0;
    vector<set<int>> dp(q + 1);
    dp[p].emplace(k);
    
    while (q--) {
        int num; cin >> num;
        char c; cin >> c;
        for (auto cara: dp[p]) {
            if (c == '?') {
                dp[p + 1].emplace((cara + num) % n);
                dp[p + 1].emplace(((cara - num) + n) % n);
            }
            if (c == '0') dp[p + 1].emplace(abs(cara + num) % n);
            if (c == '1') dp[p + 1].emplace(((cara - num) + n) % n);
        }
        p++;
    }

    cout << dp[p].size() << endl;
    for (auto cara: dp[p]) cout << cara + 1 << " ";
    cout << endl;
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
