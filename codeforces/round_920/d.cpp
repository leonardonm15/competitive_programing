#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m; cin >> n >> m;
    long long resp = 0;
    vector<int> a(n);
    vector<int> b(m);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    /* cout << "a -> "; */
    /* for (auto c: a) cout << c << " "; */
    /* cout << endl; */

    /* cout << "b -> "; */
    /* for (auto c: b) cout << c << " "; */
    /* cout << endl; */

    int l = 0;
    int r = a.size() - 1;

    int L = 0;
    int R = b.size() - 1;

    long long d = 0;

    while (l <= r) {
        if (abs(a[l] - b[R]) > abs(a[r] - b[L])) {
            d += abs(a[l] - b[R]);
            l++;
            R--;
        }
        else {
            d += abs(a[r] - b[L]);
            r--;
            L++;
        }
        /* cout << "d -> " << d << endl; */
    }

    cout << d << endl;
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
