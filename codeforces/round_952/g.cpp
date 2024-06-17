#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int MOD = 1e9 + 7;

int bpow(int a, int k) {
    int b = 1;
    while (k) {
        if (k&1) {
            b *= a;
            b %= MOD;
        }
        a *= a;
        a %= MOD;
        k >>= 1;
    }

    return b;
}

void solve () {
    int l, r, k; cin >> l >> r >> k;

    int a = bpow((9 / k) + 1, l);
    int b = bpow((9 / k) + 1, r);

    cout << b - a << endl;
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
