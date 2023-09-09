#include <bits/stdc++.h>

using namespace std;
# define int long long

void solve () {
    int n; cin >> n;
    int increment = 0;
    if (n < 5) {
        cout << 0 << endl;
        return;
    }
    while (n % 5 != 0 ) n--;
    if (n >= 25) {
        increment = n/25;
    } 
    int resp = n / 5;
    resp += increment;
    cout << resp << endl;
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
