#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, d; cin >> n >> d;
    set<int> resp;
    resp.emplace(1);

    if (d == 6 || d == 3) {
        resp.emplace(3);
    }

    if (d == 5) {
        resp.emplace(5);
    }

    if (d == 7) {
        resp.emplace(7);
    }

    if (d == 9) {
        resp.emplace(3);
        resp.emplace(9);
    }

    if (n >= 3) {
        resp.emplace(7);
    }

    if (n >= 3) {
        resp.emplace(3);
    }

    if (n >= 9) {
        resp.emplace(9);
    }

    if (n <= 8) {
        int mult = 1;
        for (int i = 1; i <= n; i++) {
            mult *= i;
        }

        if ((mult * d) % 9 == 0) resp.emplace(9);
    }

    for (auto c: resp) cout << c << " ";
    cout << endl;

    /* int v = 9; */
    /* int r = 9; */

    /* for (int i = 0; i < 15; i++) { */
    /*     cout << v << " - " << v % 7 << endl; */
    /*     v *= 10; */
    /*     v += r; */
    /* } */
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
