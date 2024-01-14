#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int k = n;
    bool flag = true;
    while (flag) {
        cout << "---------------------" << endl;
        int v = 1;
        int bloq = 0;
        int add = 0;
        if (k % 10 >= 4) add++;
        while (k >= 4) {
            int q = ((k/10) * v) - bloq;
            bloq = q - bloq; // o proximo - os anteriores
            add += q;
            k /= 10;
            v *= 10;
        }
        k = add;
        /* cout << "v -> " << v << endl; */
        /* cout << "add -> " << add << endl; */
        /* cout << "add * v -> " << add * v << endl; */
        cout << "n -> " << n << endl;
        n += (add * v);
        cout << "n -> " << n << endl;
        if (k < 4) flag = false;;
    }
    if (n % 10 == 4) n++;
    cout << n << endl;
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
