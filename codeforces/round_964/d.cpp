#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string s; cin >> s;
    string r; cin >> r;

    int p = 0;

    for (auto &c: s) {
        if (c == r[p] && p < (int) r.size()) p++;
        else if (c == '?') {
            c = r[min((int)r.size() - 1ll, p)];
            p++;
        }
    }

    if (p >= (int) r.size()) {
        cout << "YES" << endl;
        cout << s << endl;
    } else {
        cout << "NO" << endl;
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
