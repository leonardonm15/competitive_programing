#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int a, b, c; cin >> a >> b >> c;
    int resp = 0;
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            for (int k = 0; k <= 5; k++) {
                if (i + j + k > 5) continue;
                resp = max(resp, (a + i) * (b + j) * (c + k));
            }
        }
    }

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
