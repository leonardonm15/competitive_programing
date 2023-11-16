#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    string s; cin >> s;
    string k;
    for (int i=0; i < 19; i++) k.append("Yes");
    cout << (-1 == k.find(s) ? "NO" : "YES") << endl;
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
