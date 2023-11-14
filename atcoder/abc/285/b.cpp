#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    for (int i=1; i < n; i++) {
        int j = 0;
        while (j + i < n && s[j] != s[j + i] ) j++;
        cout << j << endl;
    }
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
