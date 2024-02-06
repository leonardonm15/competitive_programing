#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m, k; cin >> n >> m >> k;
    set<int> set;
    map<int, int> map;
    vector<int> a(n);
    vector<int> b(m);

    for (int i=0; i < n; i++) {
        cin >> a[i];
        map[a[i]] = 1;
    }

    for (int i=0; i < m; i++) {
        cin >> b[i];
        if (map[b[i]] == 1) map[b[i]] = 3;
        else if (!map[b[i]]) map[b[i]] = 2;
    }

    int ca = 0;
    int cb = 0;
    int c = 0;
    for (int i=1; i <= k; i++) {
        if (!map[i]) {
            cout << "NO" << endl;
            return;
        } 
        else if (map[i] == 1) ca++;
        else if (map[i] == 2) cb++;
        else c++;
        /* cout << "map[i] -> " << map[i] << endl; */
    }


    int ra = max(0, (k / 2) - ca);
    int rb = max(0, (k / 2) - cb);

    /* cout << "ca -> " << ca << endl; */
    /* cout << "cb -> " << cb << endl; */
    /* cout << "ra -> " << ra << endl; */
    /* cout << "rb -> " << rb << endl; */
    /* cout << "c -> " << c << endl; */

    if (ra + rb > c || ca + cb + c < k) {
        cout << "NO" << endl;
    } else cout << "YES" << endl;
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
