#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    int resp = 0;
    int l = 2;
    int r = (n&1 ? n - 1 : n);

    resp = ((l + r) * (n / 2)) / 2;
    resp += (n + 1) / 2;

    cout << resp << endl;
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
