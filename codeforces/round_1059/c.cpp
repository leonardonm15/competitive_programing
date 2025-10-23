#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
        int a, b; cin >> a >> b;

        int fdb = 0;
        int fda = 0;
        for (int i = 31; i >= 0; i--) {
                if ((b & (1 << i))) fdb = max(fdb, i);
                if ((a & (1 << i))) fda = max(i, fda);
        }

        if (fdb > fda) cout << -1 << endl;
        else {
                if (a == b) cout << 0 << endl;
                else {
                        cout << 2 << endl;
                        int falta = (a ^ (1 << fda)) ^ ((1 << fda) - 1);
                        cout << falta << " ";
                        a ^= falta;
                        cout << (a ^ b) << endl;

                        //cout << "falta -> " << bitset<10>(falta) << endl;
                        //cout << bitset<10>((falta ^ a)) << endl;
                        //cout << bitset<10>(b) << endl;
                }
        }
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
