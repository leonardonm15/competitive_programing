#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> sarr;
    map<int, vector<int>> map;

    for (int i=0; i < n; i++) {
        cin >> arr[i];
        sarr.push_back(arr[i]);
    }

    sort(sarr.begin(), sarr.end());

    for (auto cara: arr) {
        cout << bitset<5>(cara) << endl;
    }

    for (int i=0; i < n; i++) {
        if (sarr[i] == arr[i]) continue;
        int msk = arr[i];
        msk = (msk & ~(1 << 0));
        msk = (msk & ~(1 << 1));

        while (!(msk & (1 << 2))) {
            map[arr[i]].push_back(msk);
            msk <<= 1;
        }
    }


}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
