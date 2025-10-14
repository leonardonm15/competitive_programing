#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 4000 + 5;

int dp[N];

void solve () {
    int n, k; cin >> n >> k;
    dp[0] = 1;

    for (int i = n; i >= 0; i--) {
        for (int 
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
