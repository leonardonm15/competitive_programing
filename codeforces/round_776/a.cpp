#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    string s; cin >> s;
    char c; cin >> c;

    int n = s.size();
    for (int i=0; i < n; i++) {
        if (s[i] == c) {
                /* cout << "i -> " << i << endl; */
                /* cout << "resto -> " << (n - (i + 1)) << endl; */
            if (i % 2 == 0 && (n - (i + 1)) % 2 == 0) {
                cout << "YES" << endl;
                return;
            }
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
