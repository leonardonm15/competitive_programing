#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> f(26);
    string s; cin >> s;
    for (auto cara: s) {
        f[cara - 'a']++;
    }
    int mx = *(max_element(f.begin(), f.end()));
    if (n%2 == 0) {
        if (mx > n/2) cout << max(0, abs(mx - (n - mx))) << endl;
        else cout << 0 << endl;
    } else {
        if (mx > n/2) cout << max(1, abs(mx - (n - mx))) << endl;
        else cout << 1 << endl;
    }
    /* else cout << 0 << endl; */
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
