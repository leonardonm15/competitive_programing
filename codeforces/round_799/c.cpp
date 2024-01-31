#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    vector<string> v;
    v.push_back("..........");
    for (int i=1; i <= 8; i++) {
        string s; s += ".";
        string k; cin >> k;
        s += k;
        s += ".";
        v.push_back(s);
    }

    /* v.push_back(".........."); */
    /* cout << " ---------- " << endl; */
    /* for (auto cara: v) cout << cara << endl; */

    for (int i=1; i <= 8; i++) {
        for (int j=1; j <= 8; j++) {
            if (v[i - 1][j - 1] == '#' &&
                    v[i - 1][j + 1] == '#' &&
                        v[i + 1][j - 1] == '#' &&
                            v[i + 1][j + 1] == '#' &&
                                v[i][j] == '#') {
                cout << i << " " << j << endl;
                return;
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
