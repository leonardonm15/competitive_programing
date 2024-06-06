#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    set<int> set;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        set.emplace(arr[i]);
    }

    vector<int> vec;
    vector<int> diffs;

    for (auto cara: set) vec.push_back(cara);

    for (int i=1; i < (int)vec.size(); i++) {
        diffs.push_back(vec[i] - vec[i - 1]);
    }

    int l = 0;
    int r = 0;
    int resp = 1;
    while (r < (int) vec.size()) {
        if (vec[r] - vec[l] < n) {
            resp = max(resp, r - l + 1);
            r++;
        } else {
            l++;
        }
    }

    cout << resp << endl;
}

signed main() {
    // ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
