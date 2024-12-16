#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
/* #define int long long */

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> sarr(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sarr[i] = arr[i];
    }
    
    sort(sarr.begin(), sarr.end());
    int curr = 1;
    for (auto c: sarr) {
        if (!mp[c]) mp[c] = curr++;
    }

    vector<int> narr;
    map<int, int> freq;

    for (auto c: arr) {
        int v = mp[c];
        narr.push_back(v);
        freq[v]++;
    }

    auto atual = freq.begin();
    while (atual != freq.end()) {
        
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
