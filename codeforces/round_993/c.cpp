#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int m, a, b, c; cin >> m >> a >> b >> c;
    
    int resp = 0;
    /* int r1 = 0; */
    /* int r2 = 0; */

    resp += min(m, a);
    /* r1 = m - min(m, a); */
    a -= min(m, a);

    resp += min(m, b);
    /* r1 = m - min(m, b); */
    b -= min(m, b);

    if (resp <= 2 * m) resp = min(2 * m, resp + c);
    /* if (resp + b <= 2 * m) resp += b; */

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
