#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
//

void solve () {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    int resp = 1e18 + 1;

    for (int i=0; i < n; i++) cin >> v[i];

    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    sort(v.begin(), v.end());
    resp = v[0];
    for (int i=0; i < n - 1; i++) resp = min(resp, v[i + 1] - v[i]);

    if (k == 1) {
        cout << resp << endl;
        return;
    }

    for (int i=0; i < n; i++) for (int j=0; j < i; j++) {
        int q = abs(v[i] - v[j]);
        int p = lower_bound(v.begin(), v.end(), q) - v.begin();
        if (p < n) resp = min(resp, abs(q - v[p]));
        if (p > 0) resp = min(resp, abs(q - v[p - 1]));
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
