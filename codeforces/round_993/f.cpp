#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m, q; cin >> n >> m >> q;

    vector<int> a(n);
    vector<int> b(m);

    vector<int> l(n);
    vector<int> b(m);


    int somaa = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        somaa += a[i];
    }

    int somab = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        somab += b[i];
    }

    for (int i = 0; i < n; i++) {
        l[i] = 
    }

    /* int soma_grid = 0; */

    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < m; j++) { */
    /*         grid[i][j] = a[i] * b[j]; */
    /*         soma_grid += grid[i][j]; */
    /*     } */
    /* } */


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
