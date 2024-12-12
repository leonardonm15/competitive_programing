#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        bool flag = true;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            if (abs(arr[i] - arr[j]) % k == 0) flag = false;
        }

        if (flag == true) {
            cout << "YES" << endl;
            cout << i + 1 << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
