#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int resp = 1e9;
    for (int i = 0; i < n; i++) {
        int k = i;
        int ans = 0;
        vector<int> a = arr;

        for (int i = k - 1; i >= 0; i--) {
            if (a[i + 1] < a[i]) {
                a[i] = a[i + 1];
                ans++;
            }
        }

        for (int i = k + 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                a[i] = a[i - 1];
                ans++;
            }
        }

        resp = min(resp, ans);
    }

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
