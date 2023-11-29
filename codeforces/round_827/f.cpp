#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    // After each operation, determine if it is possible to rearrange the characters of s and t 
    // s < t
    /* cout << "que porra que ta acontecendo" << endl; */
    vector<long long> ls (26);
    vector<long long> lt (26);
    int mlt = 0; // max idx letra t
    int mls = // max idx letra s;
    ls[0]++;
    lt[0]++;
    while (n--) {
        int q, t; cin >> q >> t;
        string s; cin >> s;
        if (q == 1) {
            for (auto cara: s) {
                ls[cara - 'a'] += t;
                mls = max(mls, (long long ) cara - 'a');
            }
        } 
        if (q == 2) {
            for (auto cara: s) {
                mlt = max(mlt, (long long) cara - 'a');
                lt[cara - 'a'] += t;
            }
        }
        if (mlt > 0) {
            cout << "YES" << endl;
        } else {
            if (ls[0] < lt[0] && mls <= mlt) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
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
