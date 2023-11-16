#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int l, r, jump; cin >> l >> r >> jump;
    int a, b; cin >> a >> b;

    int distbl = abs(b - l);
    int distbr = abs(r - b);

    int distal = abs(a - l);
    int distar = abs(r - a);;

    int ddl = abs(distbl - distbr);
    int ddr = abs(distal - distar);

    int d = abs(a - b);

    if (a == b) {
        cout << 0 << endl;
        return;
    }

    if (d >= jump) {
        cout << 1 << endl;
        return;
    }

    /* cout << "distbl -> " << distbl << endl; */
    /* cout << "distbr -> " << distbr << endl; */
    // 
    
    if ((distbl < jump && distbr < jump) || jump > abs(r - l) || (distal < jump && distar < jump)) {
        cout << -1 << endl;
        return;
    }
    // l + dist entre eles >= x ou r < dist entre eles
    int cpdb = min(distbl, distbr);
    int cpda = min(distal, distar);

    /* if (d < jump && (cpdb < jump && cpda < jump)) { */
    /*     cout << 3 << endl; */
    /*     return; */
    /* } */

    if ((distar >= jump && distbr >= jump) || (distal >= jump && distbl >= jump)) {
        cout << 2 << endl;
        return;
    }
    cout << 3 << endl;
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
