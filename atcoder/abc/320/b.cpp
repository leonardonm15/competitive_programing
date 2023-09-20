#include <bits/stdc++.h> 

using namespace std;
//#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();
    for (int i=n; i >= 0; i--) { 
        int l = 0;
        int r = i;
        while (r < n) {
            bool flag = true;
            bool sub = 0;
            for (int k = l; k <= ((l + r) / 2); k++) {
                //cout << l << " " << r << endl;
                if (s[k] != s[r - k]){
                    flag = false;
                    break;
                } 
                if (k == r - k) {
                    cout << 1 << endl;
                    return;
                }
                else {
                    cout << k << " " << r - k << endl;
                    cout << s[k] << " " << s[r - k] << endl;
                }
            }
            if (flag) {
                r++;
                l++;
                cout << r << " " << l << endl;
                cout << (r - l) + 1 << endl;
                return;
            }
            r++;
            l++;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
