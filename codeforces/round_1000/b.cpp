#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, l, r; cin >> n >> l >> r;
    l--;
    r--;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> pref;
    vector<int> range;
    vector<int> suf;
    for (int i = 0; i < l; i++) pref.push_back(arr[i]);
    for (int i = l; i <= r; i++) range.push_back(arr[i]);
    for (int i = r + 1; i < n; i++) suf.push_back(arr[i]);

    sort(pref.begin(), pref.end());
    sort(range.rbegin(), range.rend());
    sort(suf.begin(), suf.end());
    int resp = 0;
    int r1 = 0;
    int r2 = 0;

    for (int i = 0; i < r - l + 1; i++) resp += range[i];

    if (pref.size()) {
        for (int i = 0; i < r - l + 1; i++) {
            if (i < (int) pref.size()) {
                r1 += min(pref[i], range[i]);
            } else {
                r1 += range[i];
            }
        }

        resp = min(resp, r1);
    }

    if (suf.size()) {
        for (int i = 0; i < r - l + 1; i++) {
            if (i < (int) suf.size()) {
                r2 += min(suf[i], range[i]);
            } else {
                r2 += range[i];
            }
        }

        resp = min(resp, r2);
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
