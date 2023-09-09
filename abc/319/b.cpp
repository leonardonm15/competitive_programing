#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    string resp;
    resp.push_back('1');
    for (int i=1; i <= n; i++) {
        int minimo = 10;
        char inp;
        for (int j=1; j <= 9; j++) {
            if ((n % j) == 0 && i % (n/j) == 0) {
                inp = '1' + (j - 1);
                resp.push_back(inp);
                minimo = 0;
                break;
            }
        }
        if (minimo == 10) resp.push_back('-');
    }
    cout << resp << endl;
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
