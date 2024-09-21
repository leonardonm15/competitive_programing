#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    int r = n;
    int l = max(1ll, n - k + 1);
    int d = (r - l + 1);
    cout << "d -> " << d << endl;

    if (!(l&1) && d % 4 == 0) cout << "YES" << endl;
    else if (l == r && !(l&1)) cout << "YES" << endl;
    else if ((l&1 && d == 3) || (l&1 && d > 3 && (d - 3) % 4 == 0)) cout << "YES" << endl;
    else cout << "NO" << endl;

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
