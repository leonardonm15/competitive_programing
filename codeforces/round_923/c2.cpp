#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
void solve () {
    int n, m, k; cin >> n >> m >> k;
    map<int, int> f;
    map<int, int> a;
    map<int, int> b;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        a[num]++;
    }

    for (int i=0; i < m; i++) {
        int num; cin >> num;
        b[num]++;
    }

    int qa = 0;
    int qb = 0;
    int coringa = 0;
    for (int i=1; i <= k; i++) {
        if (a[i] > 0 && b[i] == 0) qa++;
        if (a[i] == 0 && b[i] > 0) qb++;
        if (a[i] > 0 && b[i] > 0) coringa++;
        else if (a[i] == 0 && b[i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    if (qa > k/2 || qb > k/2) {
        cout << "NO" << endl;
        return;
    }

    coringa -= (k / 2) - qa;
    coringa -= (k / 2) - qb;

    /* cout << "qa -> " << qa << endl; */
    /* cout << "qb -> " << qb << endl; */

    cout << (coringa >= 0 ? "YES" : "NO") << endl;
    /* if ((coringa - (((k/2) - qa) + ((k/2) - qb))) >= 0) cout << "YES" << endl; */
    /* if ((coringa + qa + qb) >= k) cout << "YES" << endl; */
    /* else cout << "NO" << endl; */
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
