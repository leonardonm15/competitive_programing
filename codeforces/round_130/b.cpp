#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    vector<int> prf;
    prf.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    int c = 0;
    for (int i=0; i < n; i++) {
        c += arr[i];
        prf.push_back(c);
    }
    
    /* for (auto cara: prf) cout << cara << " "; */
    /* cout << endl; */

    while (q--) {
        int m, k; cin >> m >> k;
        int sz = prf.size() - 1;
        /* cout << "prf[n - k] -> " << prf[n - k] << endl; */
        /* cout << "prf[n - (m + 1)] -> " << prf[n - (m + 1)] << endl; */
        int idx = sz - m;
        cout << prf[(sz - m) + k] - prf[sz - m] << endl;

    }
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
