#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool contains(int l, int r, int L, int R) {
    /* cout << "l -> " << l << endl; */
    /* cout << "r -> " << r << endl; */
    /* cout << "L -> " << L << endl; */
    /* cout << "R -> " << R << endl; */
    if (l >= L && r <= R) return true;
    else if (l > R || r < L) return false;
    else return false;
}

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    int ls = -1;
    int rs = -1;
    int lp = -1;
    int rp = -1;
    int err = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') continue;

        /* cout << "--------------------" << endl; */
        if (s[i] == 'p') {
            if (lp == -1) {
                lp = 0;
                rp = i;
            }

            if (ls == -1) continue;
            rp = i;
            if (!contains(lp, rp, ls, rs) && !contains(ls, rs, lp, rp)) err++;
        }

        if (s[i] == 's') {

            if (ls == -1) {
                ls = i;
                rs = n - 1;
            }

            /* bool ba = contains(lp, rp, ls, rs); */
            /* cout << "ba -> " << ba << endl; */
            /* bool bb = contains(ls, rs, lp, rp); */

            /* cout << "bb -> " << bb << endl; */

            if (lp == -1) continue;
            ls = i;
            if (!contains(lp, rp, ls, rs) && !contains(ls, rs, lp, rp)) err++;
        }

        /* cout << lp << " " << rp << " | " << err << endl; */
        /* cout << ls << " " << rs << endl; */

    }


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
