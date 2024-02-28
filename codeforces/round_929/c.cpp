#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
    // ----------    GRIND MENTALITY    ---------     

void solve () {
    int a, b, l; cin >> a >> b >> l;
    int k = l;
    int na = 0;
    int nb = 0;
    while (k >= a) {
        k /= a;
        na++;
    }
    
    k = l;
    while (k >= b) {
        k /= b;
        nb++;
    }

    /* cout << "na -> " << na << endl; */
    /* cout << "nb -> " << nb << endl; */
    set<int> set;
    for (int i=0; i <= na; i++) {
        for (int j=0; j <= nb; j++) {
            int k = l;
            int u = (int) pow(a, i);
            int v = (int) pow(b, j);
            /* cout << "a -> " << a << endl; */
            /* cout << "b -> " << b << endl; */
            k /= u;
            k /= v;
            if ((k * u * v) == l) set.emplace(k);
        }
    }

    /* cout << "set -> "; */
    /* for (auto cara: set) cout << cara << " "; */
    /* cout << endl; */
    cout << set.size() << endl;
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
