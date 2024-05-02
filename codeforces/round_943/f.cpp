#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    vector<int> pref(n + 1);
    int xorada = 0;
    for (int i=1; i <= n; i++) {
        xorada ^= arr[i - 1];
        map[xorada].push_back(i);
        pref[i] = xorada;
    }

    while (q--) {
        int l, r; cin >> l >> r;

        int tg = pref[l - 1] ^ pref[r];
        if (!tg) cout << "YES" << endl;
        else {
            map<int, bool> map;
            while (l
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
