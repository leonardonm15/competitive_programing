#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> a(n, -1);
    vector<int> b(n);
    vector<int> pref(n);
    int soma = 0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        soma += a[i];
        pref[i] = soma;
    }
    int mx = -1;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        mx = max(mx, num);
        b[i] = mx;
    }
    
    /* cout << "pref -> "; */
    /* for (auto cara: pref) cout << cara << " "; */
    /* cout << endl; */

    /* cout << "b -> "; */
    /* for (auto cara: b) cout << cara << " "; */
    /* cout << endl; */

    // quantidade de vezes que tenho que mult
    int resp = 0;
    int i = min(n - 1, k - 1);
    while (i >= 0) {
        int sat = pref[i];
        int q = max(0ll, (k - 1) - i);
        /* cout << "q -> " << q << endl; */
        resp = max(resp, sat + (q * b[i]));
        i--;
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
