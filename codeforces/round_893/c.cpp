#include <bits/stdc++.h>

using namespace std;
//#define int long long


void solve () {
    int n; cin >> n;
    vector<int> sv(n + 5);
    cout << 1 << " ";
    for (int i=2; i <= n; i++) {
        if (!sv[i]) {
            sv[i]++;
            cout << i << " ";
            for (int j=i + i; j <= n; j *= 2) {
                sv[j]++;
                cout << j << " ";
            }
        }
    }
    cout << endl;
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
