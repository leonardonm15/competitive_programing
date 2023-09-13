#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n + 5);
    vector<int> pref(n + 5);
    int x0 = 0, x1 = 0;
    for (int i=1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = arr[i] ^ pref[i - 1];
    }
    string num; cin >> num;
    for (int i=0; i < n; i++) {
        if (num[i] == '1') x1 ^= arr[i + 1];
        else x0 ^= arr[i + 1];
    }
    int q; cin >> q;
    cout << "resp -> ";
    while (q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int l, r; cin >> l >> r;
            int res = pref[l - 1] ^ pref[r];
            x0 ^= res;
            x1 ^= res;
        } else {
            int num; cin >> num;
            if (num&1) cout << x1 << " ";
            else cout << x0 << " ";
        }
    }
    cout << endl;
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
