#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int m, n; cin >> m >> n;
    map<int, int> map;
    int maxi = 0;
    int nmaxi = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        map[num]++;
        if (map[num] > maxi || (maxi == map[num] && num < nmaxi)) {
            nmaxi = num;
            maxi = map[num];
        }
        cout << nmaxi << endl;
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
