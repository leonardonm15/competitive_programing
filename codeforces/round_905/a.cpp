#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    string s; cin >> s;
    int resp = 4;
    int ci = 1;
    for (int i=0; i < 4; i++) {
        int num = s[i] - '0'; 
        if (num == 0) num = 10;
        resp += abs(num - ci);
        ci = num;
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
