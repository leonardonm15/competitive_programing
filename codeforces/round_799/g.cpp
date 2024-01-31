#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    k++;

    vector<int> v(n);
    int mx = LLONG_MAX;
    v.push_back(mx);

    for (int i=0; i < n; i++) cin >> v[i];

    int resp = 0;
    for (int i=0; i < n;) {
        int c = 0;
        /* cout << "i -> " << i << endl; */
        while (i < n && v[i] < (v[i + 1] * 2)) {
            i++;
            c++;
        }
        /* cout << "i -> " << i << endl; */
        /* cout << "c -> " << c << endl; */

        if (c > 0) {
            c++;
            resp += max(0ll, (c - k) + 1);
        } else {
            i++;
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
