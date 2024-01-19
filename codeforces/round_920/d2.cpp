#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < m; i++) cin >> b[i];

    /* cout << "a -> "; */
    /* for (auto c: a) cout << c << " "; */
    /* cout << endl; */

    /* cout << "b -> "; */
    /* for (auto c: b) cout << c << " "; */
    /* cout << endl; */

    long long d = 0;
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    for (int i=0; i < n; i++) {
        d += abs(a[i] - b[i]);
    }

    long long k = 0;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    for (int i=0; i < n; i++) {
        k += abs(a[i] - b[i]);
    }

    cout << max(k, d) << endl;
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
