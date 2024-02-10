#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m, c; cin >> n >> m >> c;
    int p = 0;
    int s = 0;
    vector<int> a(m + 5);

    for (int i=0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (a[x] < c) {
            a[x]++;
            p++;
        }
        else if (a[y] < c) {
            a[y]++;
            s++;
        }
    }

    cout << p << " " << s << endl;
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
