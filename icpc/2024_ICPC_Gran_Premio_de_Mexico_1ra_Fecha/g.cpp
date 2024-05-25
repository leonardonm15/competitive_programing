#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    set<int> set;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        set.emplace(num);
    }

    cout << (set.size()&1 ? "Alicius" : "Bobius") << endl;
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
