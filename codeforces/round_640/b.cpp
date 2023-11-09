#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    int num = n - ((k - 1) * 2);
    if (k > n) {
        cout << "NO" << endl;
        return;
    }
    if ((n - (k - 1)&1)) {
        cout << "YES" << endl;
        cout << n - (k - 1) << " ";
        for (int i=0; i < k - 1; i++) cout << 1 << " ";
        cout << endl;
        return;
    } else if (num > 0 && num % 2 == 0) {
        cout << "YES" << endl;
        cout << num << " ";
        for (int i=0; i < k - 1; i++) cout << 2 << " ";
        cout << endl;
        return;
    } else {
        cout << "NO" << endl;
        return;
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
