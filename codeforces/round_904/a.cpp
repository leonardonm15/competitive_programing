#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    string x; cin >> x;
    int k; cin >> k;
    int n = x.size();
    string s;
    int resp = 0;
    for (int i=0; i < n; i++) {
        resp += s[i] - '0';
    }
    if (resp % k == 0) {
        cout << x << endl;
        return;
    }

    if (stoll(x) < k) {
        int q = k - stoll(x);
        while (q >= 9) {
            s.push_back(9);
            q -= 9;
        }
        if (q > 0) s.push_back(q);
        reverse(s.begin(), s.end());
        cout << s << endl;
    } else {
        int i = 0;
        int y = stoll(x);
        while (y % k != 0) {
            i++;
            y++;
        }
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
