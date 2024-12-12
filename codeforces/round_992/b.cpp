#include <bits/stdc++.h>

using namespace std;

/* #define endl '\n' */ 
#define int long long

void solve () {
    int n; cin >> n;
    int l = 1;
    int q = 1;
    int resp = 1;
    for (int i = 2; i <= n; i++) {
        int range = (i - 1 + 1) / 2;

        if (range == (q + 1)) {
            q = i;
            resp++;
        }
    }

    if (q < n) resp++;

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
