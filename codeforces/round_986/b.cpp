#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, b, c; cin >> n >> b >> c;

    int l = 0;
    int r = n - 1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2; // até o mid
        int opa = ((b * mid) + c);
        int need = opa - (opa / b);
        int have = r - mid - 1;

        cout << "------------------" << endl;
        cout << "Opa -> " << opa << endl;
        cout << "need -> " << need << endl;
        cout << "Have -> " << have << endl;
        cout << "Mid -> " << mid << endl;

        if (need > have) {
            r = mid - 1;
        } else if (need < have) {
            r = mid + 1;
        } else {
            ans = mid;
            break;
        }
    }

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
