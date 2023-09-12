#include <bits/stdc++.h>

using namespace std;
//#define int long long



void solve () {
    int n; cin >> n;
    vector<int> arr(n + 5);
    vector<int> pref(n + 5);
    int x0 = -1, x1 = -1;
    for (int i=1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = arr[i] ^ arr[i - 1];
    }
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        if (num&1) {
            if (x1 == -1) {
                x1 = num; 
                continue;
            }
            x1 ^= arr[i];
        } else {
            if (x0 == -1) {
                x0 = num;
                continue;
            }
            x0 ^= arr[i];
        }
    }
    int q; cin >> q;
    while (q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int l, r; cin >> l >> r;
            x0 ^= pref[l - 1] ^ pref[r];
            x1 ^= pref[l - 1] ^ pref[r];
        } else {
            int num; cin >> num;
            if (num&1) cout << x1 << endl;
            else cout << x0 << endl;
        }
    }
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
