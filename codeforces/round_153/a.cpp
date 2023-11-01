#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();
    if (s == "()") {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    bool flag = false;
    for (int i=1; i < n; i++) {
        if (s[i] == s[i - 1]) flag = true;
    }
    string r;
    if (flag) {
        for (int i = 0; i < n; i++) r.append("()");
    } else {
        for (int i=0; i < 2 * n; i++) {
            if (i <= (2 * n - 1)/2) r.push_back('(');
            else r.push_back(')');
        }
    }
    cout << r << endl;
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
