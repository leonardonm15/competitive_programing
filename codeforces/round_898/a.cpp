#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    string s; cin >> s;
    vector<int> err1;
    for (int i=0; i < 3; i++) {
        if (s[i] != 'a' + i) {
            err1.push_back(i);
        }
    }
    int n = err1.size();
    string resp = "YES";
    if (n >= 2) swap(s[err1[0]], s[err1[1]]);
    if (s != "abc") resp = "NO";
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
