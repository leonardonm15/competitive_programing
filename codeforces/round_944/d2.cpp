#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();
    int cz = 0;
    int c1 = 0;
    int resp = 1;
    bool flag = false;
    for (int i=1; i < n; i++) {
        if(s[i] == '0' && s[i - 1] == '1') {
            c1++;
        }
        if (s[i] == '1' && s[i - 1] == '0') {
            cz++;
            flag = true;
        }
    }

    if (flag) cout << c1 + cz - 1 + resp << endl;
    else cout << c1 + cz + resp << endl;
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
