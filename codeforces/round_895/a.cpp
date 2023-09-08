#include <bits/stdc++.h>

using namespace std;
#define int double 

void solve () {
    int a, b, c; cin >> a >> b >> c;
    int med = (a + b) / 2;
    int resp = max(a, b) - med;
    resp = resp / c;
    resp = ceil(resp);
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
