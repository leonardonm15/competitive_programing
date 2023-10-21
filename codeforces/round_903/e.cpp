#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int inf = 1e6 + 5;
const int maxn = 2e5 + 5;
vector<int> arr(maxn, inf);
vector<int> acc(maxn);

int dp(int num, int n) {
    /* cout << "num -> " << num << endl; */
    if (num > n) return inf;
    else if (num == n) return 0;
    if (acc[num] != -1) return acc[num];
    else {
        acc[num] = min(dp(num + arr[num] + 1, n), dp(num + 1, n) + 1);
        return acc[num];
    }
}
void solve () {
    int n; cin >> n;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        acc[i] = -1;
    }
    int resp = dp(0, n);
    cout << resp << endl;
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
