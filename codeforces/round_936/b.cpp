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

    /* vector<int> pos; */
    /* int neg = 0; */
    /* int posi = 0; */

    int soma = 0;
    vector<int> pref(n + 1);
    int mx = 0;
    int mgrau = 0;

    for (int i=1; i <= n; i++) {
        if (grau >= mgrau || mx < (arr[i - 1] + pref[i - 1])) {
            
        }
        pref[i] = max((pref[i - 1] + arr[i - 1]) % mod, 0ll);
        soma += arr[i - 1] % mod;
        /* cout << "arr[i - 1] -> " << arr[i - 1] << endl; */
    }
    

    sort(pref.rbegin(), pref.rend());

    soma -= pref[0];
    soma %= mod;

    cout << "pref -> ";
    for (auto cara: pref) cout << cara << " ";
    cout << endl;


    /* int resp = 0; */
    cout << "soma -> " << soma << endl;
    cout << "pref[0] -> " << pref[0] << endl;

    bool flag = false;
    if (soma == pref[0]) flag = true;

    while (k--) {
        pref[0] += pref[0] % mod;
    }

    pref[0] %= mod;

    if (flag) {
        cout << (mod + pref[0]) % mod << endl;
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
