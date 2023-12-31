#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    
    int q = k;
    int in = 1;
    int ik = 1;
    for (int i=2; i * i <= n; i++) {
        if (n != 1 && (k % i == 0 || n % i == 0)) {
            cout << k * i << endl;
            return;
        }
    }

    if (n == 1) {
        cout << k * k << endl;
    } else {
        cout << k * n << endl;
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
