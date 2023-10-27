#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 1e5 + 5;

void solve () {
    string s; cin >> s;
    int n = s.size();
    int cum = 0;
    int mj = maxn;
    string c;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] - '0' >= 5) {
            if (i == 0) {
                cout << 1;
                for (int j=0; j < n; j++) cout << 0;
                cout << endl;
                return;
            }
            s[i - 1]++;
            s[i] = '0';
            mj = i;
        }
        c.push_back(s[i]);
    }
    reverse(c.begin(), c.end());
    for (int i=0; i < n; i++) {
        if (i < mj) cout << c[i];
        else cout << 0;
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
