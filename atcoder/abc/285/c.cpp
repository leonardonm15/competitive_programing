#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();
    int resp = 0;
    reverse(s.begin(), s.end());
    int base = 1;
    for (int i=0; i < n; i++) {
        resp += ((s[i] - ('A' - 1)) * base);
        base *= 26;
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
