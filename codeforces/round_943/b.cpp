#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m; cin >> n >> m;
    string s, r; cin >> s >> r;

    int up = 0;
    int d = 0;
    int resp = 0;
    while (up < n && d < m) {
        if (s[up] == r[d]) {
            up++;
            d++;
            resp++;
        } else d++;
    }

    cout << resp << endl;


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
