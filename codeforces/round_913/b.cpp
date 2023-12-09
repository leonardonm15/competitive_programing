#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    string s; cin >> s;
    vector<int> lc;
    vector<int> uc;
    for (int i=0; i < s.size(); i++) {
        if (s[i] == 'b') {
            s[i] = '-';
            if (!lc.empty()) {
                s[lc.back()] = '-';
                lc.pop_back();
            }
            continue;
        } else if (s[i] == 'B') {
            s[i] = '-';
            if (!uc.empty()) {
                s[uc.back()] = '-';
                uc.pop_back();
            }
            continue;
        }
        if (s[i] < 'a') uc.push_back(i);
        else lc.push_back(i);
    }
    /* cout << s << endl; */
    for (auto cara: s) {
        if (cara == '-') continue;
        else cout << cara;
    }
    cout << endl;
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
