#include <bits/stdc++.h>

using namespace std;
//#define int long long
vector<int> arr;
vector<int> dp(2e5, -1);
int k;

int f(int x) {
    if (x == 0) return 0;
    if (x <= k) return abs(arr[0] - arr[x]);
    if (dp[x] == -1) {
        int stp3 = abs(arr[x-1] - arr[x]) + f(x-1);
        for (int i=2; x - i >= 0 && i <= k; i++) {
            int stp2 = abs(arr[x-i] - arr[x]) + f(x - i);
            stp3 = min(stp3, stp2);
        }
        dp[x] = stp3;
    }
    return dp[x];
}

void solve () {
    int n; cin >> n >> k;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }
    cout << f(n-1) << endl;
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
