#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int x, y; cin >> x >> y;

    int resp = 0;

    // quantidade de telas pra caras tamanho 2
    int t = y / 2;
    int restot = y % 2;
    
    int q = t * 7;
    x = max(x - q, 0ll);

    resp += t;
    if (restot) {
        x = max(0ll, x - 11);
        resp++;
    }

    int k = (x / 15) + ((x % 15) > 0);
    cout << resp + k << endl;
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
