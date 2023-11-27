#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    map<int, int> m1;
    map<int, int> m2;
    int k = n;
    int r1 = 0;
    int r2 = 0;
    
    /* cout << n % 6 << " " << n%4 << endl; */
    /* cout << n/6 << " " << n/4 << endl; */
    
    r1 = n / 6;
    bool flag = false;
    if (n < 6) flag = true;
    if (n % 6 != 0) {
        if ((n % 6) % 2 == 0) {
            r1++;
        } else r1 = 0;
    } 
    
    r2 = n / 4;
    if (n % 4 != 0) {
        if ((n % 4) % 2 != 0 && n % 4 != 0) {
            r2 = 0;
        }
    }
    if (flag) r1 = r2;
    if (!r1 && !r2) cout << -1 << endl;
    else cout << r1 << " " << r2 << endl;
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
