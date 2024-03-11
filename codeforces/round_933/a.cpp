#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < m; i++) cin >> b[i];

    int resp = 0;
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if ((a[i] + b[j]) <= k) resp++;
        }
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
