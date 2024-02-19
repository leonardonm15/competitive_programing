#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
/* #define int long long */

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    map<int, int> map;

    int k = n;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        int c = num ^ (INT_MAX);
        if (map[c] > 0) {
            k--;
            map[c]--;
        } else {
            map[num]++;
        }
    }

    cout << k << endl;
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
