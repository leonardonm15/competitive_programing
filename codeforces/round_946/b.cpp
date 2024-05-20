#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    set<char> set;
    string r;
    map<char, char> map;

    for (auto c: s) set.emplace(c);

    for (auto c: set) r.push_back(c);

    for (int i=0; i <= (int)r.size() / 2; i++) {
        map[r[i]] = r[(int)r.size() - 1 - i];
        map[r[(int)r.size() - 1 - i]] = r[i];
    }

    /* for (auto [c, i]: map) { */
    /*     cout << c << " vira -> " << i << endl; */
    /* } */

    string resp;
    for (auto c: s) {
        resp.push_back(map[c]);
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
