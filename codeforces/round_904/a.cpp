#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    string x; cin >> x;
    int k; cin >> k;
    int n = x.size();
    string s;
    int resp = 0;
    for (int i=0; i < n; i++) {
        resp += x[i] - '0';
    }
    int q = abs(k - resp);
    int y = stoll(x);
    while (resp % k != 0) {
        y++;
        /* cout << "resp -> " << resp << endl; */
        int aux = y;
        int m = 0;
        while (aux > 0) {
            m += aux % 10;
            aux /= 10;
        }
        resp = m;
    }
    cout << y << endl;
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
