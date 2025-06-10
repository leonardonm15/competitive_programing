#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string s; cin >> s;
    int k = stoll(s);

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (((i + j) * (i + j)) == k) {
                cout << i << " " << j << endl;
                return;
            }
        }

    }

    cout << -1 << endl;

    /* int k = (int) (s[n - 1] - '0'); */
    /* k += (int) (s[n - 2] - '0') * 10ll; */
    /* k += (int) (s[n - 3] - '0') * */ 
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
