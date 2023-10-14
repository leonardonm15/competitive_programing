#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    bool flag = false;
    while (n > 3) {
        if (n % 2 == 0) {
            n = n/2;
            continue;
        }
        if (n % 3 == 0) {
            n = n/3;
            continue;
        }
        else {
            cout << "No" << endl;
            flag = true;
            break;
        }
    }
    if (!flag) cout << "Yes" << endl;
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
