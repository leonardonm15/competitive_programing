#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    int last_num, curr;
    int resp = 0;
    cin >> last_num;
    for (int i=0; i < n - 1; i++) {
        cin >> curr;
        if (curr < last_num) resp += last_num - curr;
        if (curr > last_num) last_num = curr;
    }
    cout << resp << endl;
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
