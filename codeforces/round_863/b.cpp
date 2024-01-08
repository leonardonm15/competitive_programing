#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, a, b, x, y; cin >> n >> a >> b >> x >> y;

    int na = 0;
    int nx = 0;
    if (b > a) b -= a;
    // tenho acesso a 10 niveis
    // subi 20, em qual nivel eu to
    if (a > n / 2) a -= n / 2;
    if (b > n / 2) b -= n / 2;
    if (x > n / 2) x -= n / 2;
    if (y > n / 2) y -= n / 2;
    
    int k = max({abs(a - x), abs(b - y)});
    cout << k << endl;
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
