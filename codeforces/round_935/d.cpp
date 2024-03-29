#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);

    for (int i=n - 1; i >= 0; i--) cin >> a[i];
    for (int i=n - 1; i >= 0; i--) cin >> b[i];

    vector<int> best(n + 1);

    for (int i=1; i <= n; i++) {
        best[i] = min(a[i - 1], b[i - 1]) + best[i - 1];
    }

    int resp = 1e18 + 5;

    /* cout << "best -> "; */
    /* for (auto cara: best) cout << cara << " "; */
    /* cout << endl; */

    for (int i=n - m; i < n; i++) {
        resp = min(best[i] + a[i], resp);
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
