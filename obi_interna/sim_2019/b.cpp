#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int m, a, b; cin >> m >> a >> b;
    int maior = 0;
    maior = max(a, b);
    m -= a;
    m -= b;
    maior = max(m, maior);
    cout << maior << endl;
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
