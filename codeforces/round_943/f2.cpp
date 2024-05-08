#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, q; cin >> n >> q;
    map<int, vector<int>> mapref;
    map<int, vector<int>> mapsuf;
    vector<int> arr(n), pref, suf(n + 2);

    for (int i=0; i < n; i++) cin >> arr[i];
    int sum = 0;

    pref.push_back(sum);
    for (int i=0; i < n; i++) {
        sum ^= arr[i];
        pref.push_back(sum);
        mapref[sum].push_back(i + 1);
    }

    for (int i= n - 1; i >= 0; i--) {
        suf[i + 1] ^= (arr[i] ^ suf[i + 2]);
        mapsuf[suf[i + 1]].push_back(i + 1);
    }

    /* cout << "pref -> "; */
    /* for (auto cara: pref) cout << cara << " "; */
    /* cout << endl; */

    /* cout << "suf ->  "; */
    /* for (auto cara: suf) cout << cara << " "; */
    /* cout << endl; */

    while (q--) {
        int l, r; cin >> l >> r;
        int tg = pref[l - 1] ^ pref[r];
        if (!tg) cout << "YES" << endl;
        else {
            int tgl = tg ^ pref[l - 1];
            int tgr = tg ^ suf[r + 1];
            if (mapref.count(tgl) && mapsuf.count(tgr)) {
                auto low = lower_bound(mapref[tgl].begin(), mapref[tgl].end(), l);
                auto hight = lower_bound(mapsuf[tgr].begin(), mapsuf[tgr].end(), r, greater<int>());
                if (low != mapref[tgl].end() && hight != mapsuf[tgr].end()) {
                    cout << (*low < *hight ? "YES" : "NO") << endl;
                } else cout << "NO" << endl;
            } else {
                cout << "NO" << endl;
            }
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
