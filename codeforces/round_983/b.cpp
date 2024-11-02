#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool check(int l, int r, int n) {
    if ((l - 1)&1 && ((n - r))&1) return false;
    else return true;
}

void solve () {
    int n, k; cin >> n >> k;
    
    int l = k;
    int r = k;
    
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }

    while (check(l, r, n)) {
        if (l <= 1 || r >= n) break;
        /* cout << "l -> " << l << endl; */
        /* cout << "r -> " << r << endl; */
        l--;
        r++;
    }



    if (l <= 1 || r >= n) {
        cout << -1 << endl;
        return;
    }
    
    cout << 3 << endl;
    cout << 1 << " " << l << " " << r + 1 << endl;
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
