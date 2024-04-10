#include <bits/stdc++.h>

using namespace std;
# define int long long

void solve () {
    string s; cin >> s;
    int resp = 0;
    int lresp = 0;
    char last;
    for (int i=0; i < s.size(); i++) {
        char curr = s[i];
        if (i == 0) {
            last = s[i];
            continue;
        }
        if (last == curr) lresp++;
        resp = max(lresp, resp);
        if (last != curr) lresp = 0;
        last = curr;
    }
    resp++;
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

