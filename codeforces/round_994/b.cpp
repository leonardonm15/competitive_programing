#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool contains(int l, int r, int L, int R) {
    if (l >= L && r <= R) return true;
    else if (l > R || r < L) return false;
    else return true;
}

void solve () {
    int n; cin >> n;
    string s, s2; cin >> s;

    int l = -1;
    int r = -1;
    int err = 0;


    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') continue;

        if (s[i] == 'p') {
            if (l == -1) {
                l = 0;
                r = i;
            }

            if (ls == -1) continue;
            if (!contains(0, n - 1, l, r)) err++;
            rp = i;
        }

        if (s[i] == 's') {
            
            if (ls == -1) {
                ls = i;
                rs = n - 1;
            }

            if (lp == -1) continue;
            if (!contains(lp, rp, ls, rs) && !contains(lp, rp, ls, rs)) err++;
            ls = i;
        }
        /* cout << "--------------------" << endl; */
        /* cout << ls << " " << rs << endl; */
        /* cout << lp << " " << rp << " | " << err << endl; */
    }

    /* int cs = 0, cp = 0, p = 0; */
    /* for (int i = 0; i < n; i++) { */
    /*     if (s[i] == '.') p++; */

    /* } */

    cout << (err ? "NO" : "YES") << endl;
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
