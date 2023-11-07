#include <bits/stdc++.h>

using namespace std;
#define int long long
//

void solve () {
    int n; cin >> n;
    map<int, int> f;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        f[num]++;
        if (!f[num + 1]) f[num + 1] = 0;
    }
    int resp = 0;
    int y = 0;
    for (auto [cara , x]: f) {
        if (x > y) resp += abs(x - y);
        y = x;
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
