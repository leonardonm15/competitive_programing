#include <bits/stdc++.h>

using namespace std;
//#define int long long
#define mx 2e5+1

void solve () {
    vector<int> odi(mx);
    int n, m, c; cin >> n >> m >> c;
    int n_odi = 0;
    for (int i=0; i < n; i++) {
        int a, o; cin >> a >> o;
        if (odi[o] == 0) odi[o] = a;
    }
    int ch = 0;
    int num = odi[c];
    while (num != 0) {
        num = odi[num];
        ch++;
        if (ch == n) {
            ch = -1;
            break;
        }
    }
    cout << ch << endl;
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
