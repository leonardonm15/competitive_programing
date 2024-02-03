#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int m, n; cin >> m >> n;
    vector<int> a(m);
    vector<int> b(n);
    
    for (int i=0; i < m; i++) cin >> a[i];
    for (int i=0; i < n; i++) cin >> b[i];

    int resp = 0;
    for (int i=0; i < n;) {
        int k = b[i] - a[0];
        int c = 0;
        int j = 0;
        while ((b[i] - a[j] == k) {
            c++;
            i++;
        }
        
        cout << "c -> " << c << endl;
        if (c >= m) {
            resp += (c - m) + 1;
        }
    }

    cout << resp << endl;
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
