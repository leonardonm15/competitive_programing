#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int gauss(int d, int u) { // quantidade de termos
    int k = u - k + 1; // quantidade de termos
    int g = (u + k)
}


void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> pref;
    int sum = 0;

    pref.push_back(0);
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        pref.push_back(sum);
    }

    /* cout << "pref -> "; */
    /* for (auto cara: pref) cout << cara << " "; */
    /* cout << endl; */

    int q; cin >> q;
    while (q--) {
        int l, u; cin >> l >> u;
        int uidx = (--(upper_bound(pref.begin(), pref.end(), pref[l - 1] + u))) - pref.begin();
        int resp = LLONG_MIN;
        for (int i = min(l, uidx - 10); i < max((int)pref.size() - 1, uidx + 10); i++) {
            
        }
        
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
