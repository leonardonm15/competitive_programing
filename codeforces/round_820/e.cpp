#include <bits/stdc++.h>

using namespace std;

/* #define endl '\n' */ 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     


int calc(int l, int r) {

    // ta entre duas raizes
    // tira 1 sqrt(r) 
    // dps 1 sqrt(sqrt(r))
    // qundo achar, faz sqrt(sqrt(r)) como sendo o l e o sqrt(r) como sendo o R
    int s = (long long) sqrt(r - l);
    if (l == r) return l;
    for (int i=l; i < r; i += s) {
        int resp;
        cout << "? " << i << " " << i + s << endl;
        cin >> resp;
        if (resp == 1) {
            return calc(i, i + s);
        }
    }
    return calc(l, l + s);
}

void solve () {
    int r = 1e18;
    int l = 1;
    int answ = 0;
    int k = 0;
    while (k != 1) {

    }

    cout << "! " << answ << endl;
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
