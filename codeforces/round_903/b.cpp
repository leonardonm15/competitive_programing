#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int a, b, c; cin >> a >> b >> c;
    int d = min({a, b, c});
    vector<int> arr = {a, b, c};
    int count = 0;
    for (int i=0; i < 3; i++) {
        if (arr[i] == d) continue;
        if (arr[i] % d != 0) {
            count += 10;
            break;
        }
        count += (arr[i] / d) - 1;
        
    } if (count >= 4) cout << "NO" << endl;
    else cout << "YES" << endl;
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
