#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> arr;
    for (auto c: s) {
        if (c == 'U') arr.push_back(1);
        else arr.push_back(0);
    }

    int round = 0;
    while (s.size()) {
        pair<int, int> amm;
        for (int i=0; i < s.size(); i++) {
            if (s[i]) amm.second++;
            else amm.first++;
        }
        
        if (!(round&1) && amm.second < amm.first) {
            cout << "NO" << endl;
            return;
        }

        for (int i=0; i < s.size(); i++) {

        }
    }
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
