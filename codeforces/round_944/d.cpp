#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();

    int resp = 1;
    int spot = -1;
    for (int i=1; i < n; i++) {
        if (s[i] == '1' && s[i - 1] == '0') {
            spot = i - 1;
            break;
        }
    }

    int before_breaks = 0;
    int after_breaks = 0;
    if (spot != -1) {
        for (int i=1; i <= spot; i++) {
            if (s[i] == '0' && s[i - 1] == '1') before_breaks++;
        }

        for (int i=spot + 2; i < n; i++) {
            if (s[i] == '0' && s[i - 1] != '0') after_breaks++;
        }

        cout << "before_breaks -> " << before_breaks << endl;
        cout << "after_braeks -> " << after_breaks << endl;
        cout << before_breaks + after_breaks + resp << endl;
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
