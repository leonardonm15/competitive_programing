#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {

    cout << 63 << endl;
    for (int i = 1; i <= 63; i++) {
        cout << 63 << " " << i << endl;
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
