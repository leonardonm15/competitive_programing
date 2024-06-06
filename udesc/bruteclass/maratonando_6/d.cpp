#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    pair<int, int> amm;
    for (int i=s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') amm.first++;
        else amm.second++;
    }

    int resp = 0;
    for (int i=0; i < s.size(); i++) {
        if (s[i] == '0' && amm.second == 0 || s[i] == '1' && amm.first == 0) {
            resp += (amm.first + amm.second);
            break;
        }

        if (s[i] == '0') {
            if (amm.second > 0) amm.second--;
            else resp++;
            // if (amm.first) amm.first--;
        } else {
            if (amm.first) amm.first--;
            else resp++;
            // if (amm.second) amm.second--;
        }

    }

    cout << resp << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
