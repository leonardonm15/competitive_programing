#include <bits/stdc++.h>

using namespace std;
/* #define int long long */

void solve () {
    int m, d; cin >> m >> d;
    int Y, M, D; cin >> Y >> M >> D;

    D++;
    if (D > d) {
        M++;
        D = 1;
    }

    if (M > m) {
        Y ++;
        M = 1;
        D = 1;
    }
    
    cout << Y << " " << M << " " << D << endl;
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
