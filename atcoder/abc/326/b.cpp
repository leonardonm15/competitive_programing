#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

void solve () {
    int n; cin >> n;
    string s = to_string(n);
    int a = (s[0] - '0') * (s[1] - '0');
    while (a != (s[2] - '0') && n <= 919) {
        n++;
        s = to_string(n);
        a = (s[0] - '0') * (s[1] - '0');
    }
    cout << n << endl;
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
