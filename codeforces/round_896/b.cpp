#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, k, a, b; cin >> n >> k >> a >> b;
    vector<pair<int, int>> arr;
    for (int i=0; i < n; i++) {
        int j, k; cin >> j >> k;
        arr.push_back({j, k});
    }
    int ak = 1e13 + 5;
    int kb = 1e13 + 5;
    for (int i=0; i < k; i++) {
        int num = abs(arr[a - 1].first - arr[i].first) + abs(arr[a - 1].second - arr[i].second);
        int num2 = abs(arr[b - 1].first - arr[i].first) + abs(arr[b - 1].second - arr[i].second);
        ak = min(ak, num);
        kb = min(kb, num2);
    }

    int resp = abs(arr[a - 1].first - arr[b - 1].first) + abs(arr[a - 1].second - arr[b - 1].second);
    if (ak == 1e13 + 5 || kb == 1e13 + 5) {
        cout << resp << endl;
        return;
    }
    resp = min(resp, ak + kb);
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
