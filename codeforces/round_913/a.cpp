#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    string s; cin >> s;
    for (int i=1; i <= 8; i++) {
        if (i == (s[1] - '0')) continue;
        cout << s[0] << i << endl;
    }
    char a = 'a';
    for (int i=0; i < 8; i++) {
        if (a + i == s[0]) continue;
        cout << (char)(a + i) << (char)s[1] << endl;
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
