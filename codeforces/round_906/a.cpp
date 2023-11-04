#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    map<int, int> map;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        map[num]++;
    }
    if (map.size() == 1) {
        cout << "YES" << endl;
        return;
    }
    if (map.size() != 2) {
        cout << "NO" << endl;
        return;
    }
    for (auto [cara, f]: map) {
        if (n / 2 == f) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
