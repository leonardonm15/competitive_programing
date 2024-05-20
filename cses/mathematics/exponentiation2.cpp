#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int MOD = 1e9 + 7;

int bpow(int a, int k, int mod) {
    int resp = 1;
    while (k) {
        if (k&1) {
            resp *= a;
            resp %= mod;
        }

        a *= a;
        a %= mod;
        k >>= 1;
    }

    return resp;
}

void solve () {
    int q; cin >> q;
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        cout << bpow(a, bpow(b, c, MOD - 1), MOD) << endl;
    }
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
