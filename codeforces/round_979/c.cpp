#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

string s;

void solve () {
    int n; cin >> n;
    cin >> s;

    if (s.find("11") != -1  || s[0] == '1' || s[n - 1] == '1') cout << "YES" << endl;
    else cout << "NO" << endl;

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
