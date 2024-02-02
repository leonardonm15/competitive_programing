#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int a = 1e9 + 5;
    int b = 1e9 + 5;
    int resp = 0;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (a > b) swap(a, b);
        if (num <= a) { // numero menor que o ultimo cara, sem pena
            a = num;
        } else if (num <= b) {
            b = num;
        } else {
            a = num;
            resp++;
        }
    }

    cout << resp << endl;
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
