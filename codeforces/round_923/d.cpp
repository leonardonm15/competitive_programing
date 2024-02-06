#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> p(n);
    map<int, int> map;

    int at = 0;
    int lc = -1;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (num != lc) {
            p[i] = 1;
            lc = num;
        } else {
            p[i] = p[i - 1] + 1;
        }
    }
    

    /* cout << "p -> "; */
    /* for (auto cara: p) cout << cara << " "; */
    /* cout << endl; */

    /* cout << "-------------" << endl; */

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (b - p[b] < 0 || b - p[b] < a) {
            cout << -1 << " " << -1 << endl;
        } else {
            cout << (b - p[b]) + 1 << " " << b + 1 << endl;
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
