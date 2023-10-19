#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int inf = 1e6 + 5;
const int maxn = 1e5 + 5;
vector<int> arr(maxn, inf);

int dp(vector<int> arr, int num, int c) {
    if (num == arr.size()) return c;
    if (num > arr.size()) return inf;
    else {
        return min(dp(arr, arr[num + arr[num]], c), dp(arr, arr[num + 1], c++));
    }
}

void solve () {
    int n; cin >> n;
    arr.resize(maxn, inf);
    for (int i=0; i < n; i++) cin >> arr[i];
    int resp = min(dp(arr, arr[0 + arr[0]], 0), dp(arr, arr[1], 1));
    cout << n - resp << endl;
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
