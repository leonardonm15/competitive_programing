#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
   int a, b; cin >> a >> b;
   if ((a == b / 2) || (b == a/2)) cout << "Yes" << endl;
   else cout << "No" << endl;
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
