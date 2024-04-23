#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, p; cin >> n >> p;
    vector<int> mex(1e6);
    vector<int> gn(1e6);

    for (int i=1; i <= n; i++) {
        int k = 1;
        while (k <= i) {
            mex[gn[i - k]]++;
            k *= p;
        }

        int resp = 0;
        for (int i=0; i <= n; i++) {
            if (!mex[i]) {
                resp = i;
                break;
            }
        }

        for (int i=0; i <= n; i++) mex[i] = 0;

        gn[i] = resp;
    }

    cout << "gn -> ";
    for (int i=n; i >= 0; i--){
        cout << i << " -> " << gn[i] << endl;
    }
    cout << endl;
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
