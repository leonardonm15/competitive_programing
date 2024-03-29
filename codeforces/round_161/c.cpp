#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n + 1);
    vector<int> c(n + 1);
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    for (int i=1; i <= n; i++) cin >> arr[i];

    for (int i=1; i <= n; i++) {
        if (i == 1) c[i] = 1;
        else if (i == n) c[i] = 0;
        else {
            int a = arr[i] - arr[i - 1];
            int b = arr[i + 1] - arr[i];
            if (a < b) c[i] = 0;
            else c[i] = 1;
        }
    }
    
    /* cout << "c -> " << endl; */
    /* for (auto cara: c) cout << cara << " "; */
    /* cout << endl; */

    for (int i=2; i <= n; i++) {
        if (c[i-1]) l[i] = l[i - 1] + 1;
        else l[i] = l[i - 1] + (arr[i] - arr[i - 1]);
    }

    for (int i= n - 1; i > 0; i--) {
        if (!c[i + 1]) r[i] = r[i + 1] + 1;
        else r[i] = r[i + 1] + (arr[i + 1] - arr[i]);
    }

    /* cout << "l -> " << endl; */
    /* for (auto cara: l) cout << cara << " "; */
    /* cout << endl; */

    /* cout << "r -> " << endl; */
    /* for (auto cara: r) cout << cara << " "; */
    /* cout << endl; */

    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        if (x < y) {
            cout << l[y] - l[x] << endl;
        } else {
            cout << r[y] - r[x] << endl;
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
