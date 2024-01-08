#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, a, b, x, y; cin >> n >> a >> b >> x >> y;

    int na = 0;
    int nx = 0;

    if (a > n / 2) a = ((n / 2) + 1) - abs((n / 2) - a);
    if (b > n / 2) b = ((n / 2) + 1) - abs((n / 2) - b);
    if (x > n / 2) x = ((n / 2) + 1) - abs((n / 2) - x);
    if (y > n / 2) y = ((n / 2) + 1) - abs((n / 2) - y);
    
    na = min(a, b);
    nx = min(x, y);
    cout << abs(na - nx) << endl;
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
