#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define ll long long
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, q; cin >> n >> q;
    vector<int> arr(n);

    for (int i=0; i < n; i++) cin >> arr[i];

    while (q--) {
        int s, d, k; cin >> s >> d >> k;
        ll resp = 0;
        if (d > (int) sqrt(n)) {
            for (int i=1; i <= k; i++) {
                resp += arr[s + (d * (i - 1))] * i;
            }
        } else {
        }
        // se d for maior que 
        //  sqrt(d * k) só itera k vezes
        //
        //  else sqrt decomp (ver desenho enzo)
    }
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
