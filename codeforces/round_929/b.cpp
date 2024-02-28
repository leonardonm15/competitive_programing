#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    map<int, int> map;
    int sum = 0;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        sum += num;
        map[num % 3]++;
    }

    if ((sum % 3) == 0) {
        cout << 0 << endl;
    } else if ((sum % 3) == 1) {
        if (map[1] > 0) cout << 1 << endl;
        else cout << 2 << endl;
    } else if ((sum % 3) == 2) {
        if (map[2] > 0) cout << 1 << endl;
        else cout << 1 << endl;
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
