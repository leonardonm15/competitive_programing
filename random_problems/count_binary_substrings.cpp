#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();

    int resp = 0;
    vector<int> sz;

    int now = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            now++;
        } else {
            sz.push_back(now);
            now = 1;
        }
    }

    sz.push_back(now);

    for (int i = 1; i < (int)sz.size(); i++) {
        resp += min(sz[i], sz[i - 1]);
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
