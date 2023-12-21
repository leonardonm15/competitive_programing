#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    map<int, int> map;
    long long resp = 0;
    for (int i=0; i < n; i++) {
        string s; cin >> s;
        int msk = 0;
        for (auto c: s) msk ^=  1 << (int)(c - 'a');
        resp += map[msk];
        for (int i=0; i <= 26; i++) {
            resp += map[msk ^ (1 << i)];
        }
        map[msk]++;
    }
    cout << resp << endl;
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
