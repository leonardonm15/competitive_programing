#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int msk = 0;
    vector<int> pnts = {8, 4, 2, 1};
    while (msk < (1 << 5)) {
        int k = 0;
        /* int c = msk; */
        int resp = 0;
        for (int i=0; i < 5; i++) {
            if (msk & (1 << i)) {
                k += pnts[i];
                resp++;
            }
        }

        if (k == n) {
            cout << resp << endl;
            return;
        }

        msk++;
    }
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
