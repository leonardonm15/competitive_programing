#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int mod = 1e9 + 7;

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> grau(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    int soma = 0;
    vector<int> pref(n + 1);
    for (int i=1; i <= n; i++) {
        pref[i] = max((pref[i - 1] + arr[i - 1]), 0ll);
        soma += arr[i - 1];
        /* cout << "arr[i - 1] -> " << arr[i - 1] << endl; */
    }
    
    sort(pref.rbegin(), pref.rend());

    soma -= pref[0];

    /* int resp = 0; */
    /* cout << "soma -> " << soma << endl; */
    /* cout << "pref[0] -> " << pref[0] << endl; */

    bool flag = false;
    if (soma == pref[0]) flag = true;

    while (k--) {
        pref[0] += pref[0] % mod;
    }

    pref[0] %= mod;
    soma %= mod;

    if (flag) {
        cout << (mod + (pref[0] + soma)) % mod << endl;
        return;
    }

    cout << (mod + (soma + pref[0])) % mod << endl;
    /* cout << "resp -> " << resp << endl; */
    /* if (resp < 0) resp = mod - resp; */
    /* cout << "resp -> " << resp << endl; */

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
