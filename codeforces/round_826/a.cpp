#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    string a, b; cin >> a >> b;
    map<char, int> map;
    map['S'] = 1;
    map['M'] = 2;
    map['X'] = 3;
    if (a.size() == b.size()) {
        for (int i=0; i < a.size(); i++) {
            if (map[a[i]] > map[b[i]]) {

            }jk:
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
