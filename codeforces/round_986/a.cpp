#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, a, b; cin >> n >> a >> b;
    int x = 0, y = 0;
    string s; cin >> s;

    map<char, pair<int, int>> mp;

    mp['N'] = {0,  1};
    mp['S'] = {0, -1};
    mp['E'] = {1,  0};
    mp['W'] = {-1, 0};


    for (int i = 0; i < 100; i++) {
        for (auto c: s) {
            x += mp[c].first;
            y += mp[c].second;

            if (x == a && y == b) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
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
