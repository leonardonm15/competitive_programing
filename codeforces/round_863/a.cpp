#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    for (int i=0; i < n; i++) {
        if (s[i] - '0' < k) {
            string a;
            a.push_back('0' + k);
            s.insert(i, a);
            cout << s << endl;
            return;
        }
    }
    s += ('0' + k);
    cout << s << endl;
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
