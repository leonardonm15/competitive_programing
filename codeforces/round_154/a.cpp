#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();
    for (int k = 0; k < n; k++) {
        string num; num[0] = s[0];
        bool flag = true;
        for (int i=k + 1; i < n; i++) {
            num[1] = s[i];
            int r = stoll(num);
            for (int l = 2; l * l <= r; l++) {
                if (r % l == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << r << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
