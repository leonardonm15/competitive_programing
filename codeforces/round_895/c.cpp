#include <bits/stdc++.h> 

using namespace std;
#define int long long
 
void solve () {
    int l, r; cin >> l >> r;
    for (int i=l; i <= r; i++) {
        if (i <= 2) continue;
        for (int j=2; j * j <= i; j++) {
            if ((i - j) % j == 0) {
                cout << j << " " <<  i - j << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
