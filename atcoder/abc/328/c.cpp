#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, q; cin >> n >> q;
    int resp = 0;
    string s; cin >> s;
    vector<int> arr (n);
    for (int i=1; i < n; i++) { 
        if (s[i - 1] == s[i]) {
            resp++;
            arr[i] = resp;
        } else arr[i] = resp;
    }
    arr[n] = resp;
    while (q--) {
        int l, r; cin >> l >> r;
        l--;
        r--;
        cout << arr[r] - arr[l] << endl;
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
