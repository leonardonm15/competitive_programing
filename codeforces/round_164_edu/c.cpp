#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string a, b; cin >> a >> b;
    int sa = 0;
    int sb = 0;
    for (int i=0; i < a.size(); i++) {
        int na = a[i] - '0';
        int nb = b[i] - '0';
        if (sa < sb) {
            sa += max(na, nb);
            sb += min(na, nb);
            if (na < nb) swap(a[i], b[i]);
        } else {
            sb += max(na, nb);
            sa += min(na, nb);
            if (nb < na) swap(b[i], a[i]);
        }
    }

    cout << "sa -> " << sa << endl;
    cout << "sb -> " << sb << endl;
    cout << a << endl;
    cout << b << endl;
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
