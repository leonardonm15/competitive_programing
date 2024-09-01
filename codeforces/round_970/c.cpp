#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool check(int termos, int l, int r) {
    int k = l + (termos * (termos + 1) / 2);
    return k <= r;
}

void solve () {
    int l, r; cin >> l >> r;
    
    int L = 0;
    int R = 1e5;
    int ans = 0;
    
    while (L <= R) {
        int termos = (L + R) >> 1;
        if (check(termos, l, r)) {
            ans = termos;
            L = termos + 1;
        } else {
            R = termos - 1;
        }
    }

    cout << ans + 1 << endl;
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
