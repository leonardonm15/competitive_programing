#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    int c = (n / 2);
    if (n&1) c++;

    if (n == 1 && k == 1) {
        cout << 1 << endl;
        return;
    }

    if (k <= c) {
        int v = k * 2;
        if (v % 2 == 0) v--;
        cout << v << endl;
    } else {
        int z = 2;
        k -= c;
        int l = 1;
        int r = n - c;
        cout << "l -> " << l << endl;
        cout << "r -> " << r << endl;

        while (k > ((l + r + 1) / 2)) {
            /* cout << "l -> " << l << endl; */
            /* cout << "k - l -> " << k - l << endl; */
            l += (l + r + 1) / 2;
            cout << "r - l -> " << r - l << endl;
            z *= 2;
        }
        
        int v = (r - l) + 1;
        v = v * 2;
        if (v % 2 == 0) v--;
        cout << v * z << endl;
        /* cout << "z -> " << z << endl; */
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
