#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> map;
    vector<int> p(n + 1);
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        map[arr[i]]++;
    }

    sort(arr.begin(), arr.end());
    /* cout << "arr -> "; */
    /* for (auto cara: arr) cout << cara << " "; */
    /* cout << endl; */

    for (auto [cara, f]: map) {
        for (int i = cara; i <= n; i += cara) {
            p[i] += f;
        }
    }

    /* cout << "Pegadas -> "; */
    /* for (int i=0; i <= n; i++) cout << p[i] <<  " "; */
    /* cout << endl; */

    sort(p.rbegin(), p.rend());
    cout << p[0] << endl;
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
