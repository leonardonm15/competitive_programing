#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    string s, resp; cin >> s;
    char a = '=';
    for (int i=0; i < n; i++) {
        if (i == 0) {
            a = s[i];
            continue;
        }
        while (a != s[i] && i < n) {
            i++;
        }

        if (s[i] == a && i < n) {
            resp += a;
            a = s[i + 1];
            i++;
        }
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
