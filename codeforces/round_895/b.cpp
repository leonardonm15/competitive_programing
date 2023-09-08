#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    int casa = 1;
    for (int i=0; i < n; i++) {
        int d, s; cin >> d >> s;
        if (s % 2 == 0) s--;
        if (i == 0) {
            casa = (d  + (s / 2));
        } else { 
            if (s % 2 == 0) s--;
            casa = min(casa, (d + (s / 2)));
        }
    }
    cout << casa << endl; 
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
