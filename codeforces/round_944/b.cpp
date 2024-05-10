#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (s[i] != s[j]) {
                cout << "YES" << endl;
                swap(s[i], s[j]);
                cout << s << endl;
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
