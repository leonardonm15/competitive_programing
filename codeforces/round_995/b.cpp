#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, a, b, c; cin >> n >> a >> b >> c;

    int k = a + b + c;
    int resp = 0;

    resp += (n / k) * 3;

    n %= k;

    if (n == 0) cout << resp << endl;
    else if (a >= n) cout << resp + 1 << endl;
    else if (a + b >= n) cout << resp + 2 << endl;
    else if (a + b + c >= n) cout << resp + 3 << endl;
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
