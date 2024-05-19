#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m; cin >> n >> m;
    vector<int> resp(n);
    vector<int> mat(n);

    int c = 0;

    for (int i=0; i < n; i++) cin >> resp[i];
    for (int i=0; i < n; i++) cin >> mat[i];

    for (int i=0; i < n; i++) {
        if (resp[i] == mat[i]) c++;
    }

    /* cout << "c -> " << c << endl; */

    bool flag = false;
    for (int i=0; i < m; i++) {
        vector<int> amigos(n);
        for (int i=0; i < n; i++) cin >> amigos[i];

        int c2 = 0;
        for (int i=0; i < n; i++) {
            if (amigos[i] == resp[i]) c2++;
        }

        /* cout << "c2 -> " << c2 << endl; */

        if (c2 >= c) flag = true;
    }

    if (!flag) cout << "SIM" << endl;
    else cout << "NAO" << endl;
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
