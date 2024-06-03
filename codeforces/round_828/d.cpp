#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    int k = 1;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        k *= num;
    }

    int i = 0;
    while (!(k&1) && k) {
        k >>= 1;
        i++;
    }

    int d = n - i;
    if (d <= 0) {
        cout << 0 << endl;
        return;
    }

    int resp = 0;
    for (int i=n; i >= 0; i--) {
        if (i&1) continue;
        int v = 0;
        int j = i;
        while (j > 1) {
            v++;
            j >>= 1;
        }
        if (v <= d && d > 0) {
            d -= v;
            resp++;
        }
    }

    if (d == 0) cout << resp << endl;
    else cout << -1 << endl;
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
