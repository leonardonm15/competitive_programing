#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int r = 0;
    int resp = 0;
    for (int l=0; l < n; l++) {
        if (l > r) r = l;
        while (s[r] != '0' && r < n) r++;
        if (s[r] == '0') {
            swap(s[r], s[l]);
            resp += r - l;
            cout << resp << " ";
        } else cout << -1 << " ";
    }
    cout << endl;
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
