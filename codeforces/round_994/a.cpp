#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    int zc = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) zc++;
    }

    int am = 0;
    int range = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (range > 0) am++;
            range = 0;
        } else range++;
    }

    if (range > 0) am++;

    if (zc == n) cout << 0 << endl;
    else if (am == 1) cout << 1 << endl;
    else cout << 2 << endl;
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
