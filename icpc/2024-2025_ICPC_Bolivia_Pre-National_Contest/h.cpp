#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s; cin >> s;
    int alt = 0;
    int resp = 0;
    int idx = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i]  == '+') alt++;
        else alt--;

        if (alt > resp) {
            resp = alt;
            idx = i + 1;
        }

    }

    cout << idx << endl;
}

signed main() {
    solve();
}
