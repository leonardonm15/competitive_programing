#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> map;
    for (auto c: s) {
        map[c]++;
    }
    /* cout << "a " << endl; */
    int resp = map.size();
    for (int i=n - 1; i >= 0; i--) {
        map[s[i]]--;
        if (!map[s[i]]) map.erase(s[i]);
        resp += map.size();
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
