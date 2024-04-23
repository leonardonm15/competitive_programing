#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
vector<bool> sv;

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    set<int> set;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        set.emplace(arr[i]);
    }

    for (auto num: set) {
        for (int i=0; i < n; i++) {
            if (arr[i]
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    sv = sieve(1005);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
