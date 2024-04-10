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
    for (int i=5; i <= n; i = i * 5) {
        increment += n / i;
    }
    cout << increment << endl;
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
