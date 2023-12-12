#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<string> arr(n);
    int resp = 1e9;
    for (int i=0; i < n; i++) cin >> arr[i];

    /* for (auto cara: arr) cout << cara << " "; */
    /* cout << endl; */

    for (int q=0; q < n; q++) {
        for (int j=0; j < n; j++) {
            if (q == j) continue;
            string a = arr[q];
            string b = arr[j];
            int acc = 0;
            for (int i=0; i < k; i++) {
                acc += max(a[i], b[i]) - min(a[i], b[i]);
            } 
            resp = min(resp, acc);
        }
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
