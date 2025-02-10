#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();
    bool flag = false;

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) flag = true;
    }

    cout << (flag ? 1 : s.size()) << endl;
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
