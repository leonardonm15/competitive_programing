#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int xon(int x) {
    int k = x % 4;
    if (k == 0) return x;
    if (k == 1) return 1;
    if (k == 2) return x + 1;
    if (k == 3) return 0;
    return k;
}

int calc (int x, int i, int k) {
    int good = xon(x);
    if (k > x) return good;
    int m = k;

    for (int j = 62; j >= i; j--) {
        if ((m ^ (1ll << j)) <= x) m ^= (1ll << j);
    }

    m >>= i;

    int bad_amm = m;
    int bad = xon(bad_amm);

    if ((bad_amm + 1)&1) {
        bad <<= i;
        bad ^= k;
    } else {
        bad <<= i;
    }

    return (good ^ bad);
}

void solve () {
    int l, r, i, k; cin >> l >> r >> i >> k;
    cout << (calc(l - 1, i, k) ^ calc(r, i, k)) << endl;
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
