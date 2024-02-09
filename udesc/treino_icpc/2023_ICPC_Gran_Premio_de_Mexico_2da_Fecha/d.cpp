#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> z_function(vector<int> a) {
    int n = a.size();
    vector<int> z(n);
    int l = 0;
    int r = 0;
    for (int i=1; i < n; i++) {
        // i < r
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }

        while (i + z[i] < n && a[z[i]] == a[z[i] + i]) z[i]++;

        if (r < i + z[i]) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}


void solve () {
    int m, n; cin >> m >> n;
    vector<int> a(m);
    vector<int> b(n);
    vector<int> c;
    
    for (int i=0; i < m; i++) cin >> a[i];
    for (int i=0; i < n; i++) cin >> b[i];

    if (n == 1) {
        cout << n << endl;
        return;
    } 

    if (m > n) {
        cout << 0 << endl;
        return;
    }

    for (int i=0; i < m - 1; i++) {
        c.push_back(a[i + 1] - a[i]);
    }

    c.push_back(-1e18);

    for (int i=0; i < n - 1; i++) {
        c.push_back(b[i + 1] - b[i]);
    }

    vector<int> z = z_function(c);

    int resp = 0;
    /* cout << "z -> "; */
    for (auto cara: z) {
        /* cout << cara << " "; */
        if (cara == m - 1) resp++;
    }
    /* cout << endl; */

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
