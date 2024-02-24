#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> pref(n + 1);
    int soma = 0;
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        soma += num;
        pref[i] = soma;
    }

    if (soma % 3 != 0) {
        cout << 0 << endl;
        return;
    }

    int jump = soma / 3;
    int resp = 0;
    for (int i=0; i <= n; i++) {
        int k1 = (pref[i] + jump) % soma;
        int k2 = (pref[i] + (2 * jump)) % soma;
        auto idx = lower_bound(pref.begin(), pref.end(), k1);
        auto idx2 = lower_bound(pref.begin(), pref.end(), k2);
        if (idx == pref.end() || idx2 == pref.end()) continue;
        int c1 = idx - pref.begin();
        int c2 = idx2 - pref.begin();
        if (pref[c1] == k1 && pref[c2] == k2) resp++;
    }

    cout << resp / 3 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
