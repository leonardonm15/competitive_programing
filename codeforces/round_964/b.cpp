#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;

    int resp = 0;
    if (a1 > b1 && a2 >= b2) resp += 2;
    if (a1 == b1 && a2 > b2) resp += 2;

    if (a2 > b1 && a1 >= b2) resp += 2;
    if (a2 == b1 && a1 > b2) resp += 2;

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
