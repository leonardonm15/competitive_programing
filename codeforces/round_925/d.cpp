#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, x, y; cin >> n >> x >> y;
    int mmc = lcm(x, y);
    vector<int> vx(n);
    vector<int> vy(n);
    vector<int> arr(n);
    map<pair<int, int>, int> map;
    /* map<int, int> fx; */
    /* map<int, int> fy; */

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;
        vx[i] = num % x;
        vy[i] = num % y;
    }

    /* cout << "vx -> "; */
    /* for (auto cara: vx) cout << cara << " "; */
    /* cout << endl; */

    /* cout << "vy -> "; */
    /* for (auto cara: vy) cout << cara << " "; */
    /* cout << endl; */

    int resp = 0;
    for (int i=0; i < n; i++) {
        int k = (x - vx[i]) % x;  // quanto eu preciso para a soma dar 0
        int q = vy[i];
        if (map.count({k, q})) {
            /* cout << "-----------------" << endl; */
            /* cout << "i -> " << i << endl; */
            /* cout << "num -> " << arr[i] << endl; */
            /* cout << "k -> " << k << endl; */
            resp += map[{k, q}];
        }
        map[{vx[i], vy[i]}]++;
    }

    cout << resp << endl;
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
