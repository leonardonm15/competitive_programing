#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (abs(arr[i] - arr[i - 1]) != 5 && abs(arr[i] - arr[i - 1]) != 7) flag = false;
    }

    cout << (flag ? "YES" : "NO") << endl;
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
