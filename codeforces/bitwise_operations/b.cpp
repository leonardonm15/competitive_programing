#include <bits/stdc++.h>

using namespace std;
#define int long long

int mod = 1e9 + 7;

int bpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res %= mod;
            res *= a;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve () {
    int n, k; cin >> n >> k;
    cout << bpow(k, n) << endl;

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
