#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> resp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int i = 0; i < 4; i++) {
            if (s[i] == '#') resp.push_back(i + 1);
        }
    }

    reverse(resp.begin(), resp.end());
    for (auto c: resp) cout << c << " ";
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
