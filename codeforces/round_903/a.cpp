#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, m; cin >> n >> m;
    string x, s; cin >> x >> s;
    int resp = 0;
    int ni = 0;
    int op = 0;
    for (int i=0; i < x.size(); i++) {
        cout << "x size -> " << x.size() << endl;
        cout << "x[i] " << x[i] << " - s[ni] " << s[i] << endl;
        if (x[i] == s[ni]) ni++;
        if (x[i] != s[ni]) ni = 0;
        if (i == x.size() - 1 && ni > 0) {
            x.append(x);
            cout << "to aqui -> " << endl;
            op++;
        } 
        if (ni == s.size() - 1) {
            cout << " resp  -> " << op << endl;
            return;
        }
    }
    cout << -1 << endl;
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
