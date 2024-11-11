#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int xon (int x) {
    int k = x % 4;
    if (k == 0) return x;
    if (k == 1) return 1ll;
    if (k == 2) return x + 1;
    if (k == 3) return 0ll;
    return x;
}

void solve () {
    int l, r, i, k; cin >> l >> r >> i >> k;
    int good = xon(l - 1) ^ xon(r);

    cout << "good -> " << good << endl;

    if (k > r) {
        cout << good << endl;
        return;
    }

    int m = k; // making the highest multiple between l - r;
    for (int j = 62; j >= i; j--) {
        if ((m ^ (1ll << j)) < r) m ^= (1ll << j);
    }

    cout << "m -> " << m << endl;
    m >>= i; // xor dos numeros acima dos bits acima do 2 ^ i
    int bad = xon(m);
    if ((bad + 1)&1) {
        bad <<= i;
        bad ^= k;
    } else {
        bad <<= i;
    }

    cout << "bad -> " << bad << endl;

    cout << (bad ^ good) << endl;

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
