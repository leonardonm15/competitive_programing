#include <bits/stdc++.h>

using namespace std;
#define int long long

int f (int a, int x) {
    return (x / a) + (x % a);
}

void solve () {
    int a, l, r; cin >> l >> r >> a;
    /* if (a >= r) { */
    /*     cout << f(a, r) << endl; */
    /*     return; */
    /* } */

    /* k - 1 = max mod */
    /* min(k + (a - 1), r); */
    int p = 0;
    int k =  a * (r / a);
    if (k <= l) {
        int dist = l % a;
        dist = (a - 1) - dist;
        cout << f(a, min(l + dist, r)) << endl;
        return;
    }
    int x = f(a, k);
    int b = f(a, k - 1);
    int c = f(a, min(k + a - 1, r));
    cout << max({x, b, c}) << endl;
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
