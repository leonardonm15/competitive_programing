#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> arr(n);
    int nz = 0;
    int n1 = 0;
    for (auto c: s) {
        if (c == '1') n1++;
        else nz++;
    }

    if (nz > n1) cout << "YES" << endl;
    else {
        for (int i=1; i < n; i++) {
            if ((s[i] == '1' && s[i - 1] == '0') || (s[i] == '0' && s[i - 1] == '1')) {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
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
