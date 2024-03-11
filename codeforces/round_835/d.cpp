#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int lc = -1;
    map<pair<int, int>, int> map;
    int q = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (lc == -1) {
            lc = num;
            q++;
            continue;
        } else if (lc == num) {
            q++;
        } else {
            map[{lc, q}]++;
            q = 1;
            lc = num;
        }
    }
    map[{lc, q}]++;

    for (auto [a, f]: map) {
        cout << "a.first -> " << a.first << endl;
        cout << "a.second -> " << a.second << endl;
        cout << "f -> " << f << endl;
        if (f == 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
