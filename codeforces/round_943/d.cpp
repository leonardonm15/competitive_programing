#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k, a, b; cin >> n >> k >> a >> b;
    a--; b--;
    vector<int> pa(n), vals(n);

    for (int i=0; i < n; i++) cin >> pa[i];
    for (int i=0; i < n; i++) cin >> vals[i];

    int respa = 0;
    int respb = 0;
    
    int acca = 0;
    for (int i=0; i <= min(n, k); i++) {
        acca += vals[a];
        /* cout << "acca -> " << acca << endl; */
        /* cout << "expr -> " << acca + (vals[a] * (k - (i + 1))) << endl; */
        respa = max(respa, acca + (vals[a] * (k - (i + 1))));
        a = pa[a] - 1;
    }

    int accb = 0;
    for (int i=0; i <= min(n, k); i++) {
        accb += vals[b];
        respb = max(respb, accb + (vals[b] * (k - (i + 1))));
        b = pa[b] - 1;
    }

    /* cout << "respa -> " << respa << endl; */
    /* cout << "respb -> " << respb << endl; */

    cout << (respa == respb ? "Draw" : (respa > respb ? "Bodya" : "Sasha")) << endl;
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
