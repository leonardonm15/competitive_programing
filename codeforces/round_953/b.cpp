#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, a, b; cin >> n >> a >> b;

    b = max(b, a);
    t = min(b - a, n);
    int ans = 1 * (b + b - t + 1) * t / 2 + 1 * a * (n - t);
    cout << ans << endl;
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
