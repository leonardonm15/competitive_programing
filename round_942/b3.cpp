#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    pair<int, int> amm;
    for (int i=0; i < n; i++) {
        if (s[i] == 'U') amm.second++;
        else amm.first++;
    }

    if (n == 2) {
        cout << "NO" << endl;
        return;
    }

    cout << (amm.second > amm.first ? "YES" : "NO") << endl;
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
