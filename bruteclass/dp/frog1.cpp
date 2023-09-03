#include <bits/stdc++.h>

using namespace std;
/* #define int long long */

vector<int> arr;
vector<int> dp(2e5, -1);

int f(int x) {
    if (x == 0) return 0;
    if (x == 1) return abs(arr[0] - arr[1]);
    if (dp[x] == -1) {
        int stp1 = f(x-1) + abs(arr[x-1] - arr[x]);
        int stp2 = f(x-2) + abs(arr[x-2] - arr[x]);
        dp[x] = min(stp1, stp2);
    }
    return dp[x];
}

void solve () {
    int n; cin >> n;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    } 
    cout << f(n - 1) << endl;
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
