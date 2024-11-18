#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, b, c; cin >> n >> b >> c;

    if (b == 0 && c + 2 >= n) {
        if (c >= n) cout << n << endl;
        else cout << n - 1 << endl;
        return;
    }

    if (b == 0 && c + 2 < n) {
        cout << -1 << endl;
        return;
    }

    int R = n - 1;
    int l = 0;
    int r = n - 1;
    int ans = -2;

    if (b > 0) ans = -1;

    while (l <= r) {
        int i = (l + r) >> 1;
        
        if (b >= (1e18 / i)) {
            r = i - 1;
            if (ans == r) break;
            continue;
        }

        int ge = b * i + c; // greates element
        int rs = R - i; // right side
        int elements = ge / b;
        int misses = ge - elements + 1;

        cout << "------------------" << endl;
        cout << "i -> " << i << endl;
        cout << "greatest_element -> " << ge << endl;
        cout << "rigt side -> " << rs << endl;
        cout << "elements -> " << elements << endl;
        cout << "Misses -> " << misses << endl;
        cout << "r -> " << r << endl;

        if (misses > rs) {
            r = i - 1;
            if (ans == r) break;
        } else if (misses < rs) {
            l = i + 1;
            ans = i;
        } else {
            ans = i;
            break;
        }
    }

    cout << "ans -> " << ans << endl;
    if (ans == -2) cout << -1 << endl;
    else cout << R - ans << endl;
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
