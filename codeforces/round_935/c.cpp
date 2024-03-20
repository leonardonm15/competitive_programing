#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    string s; cin >> s;

    // 0 left 1 right

    int sat = 0;
    for (int i= n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            sat++;
        }
        r[i] = sat;
    }

    sat = 0;
    for (int i=0; i < n; i++) {
        if (s[i] == '0') {
            sat++;
        }
        l[i] = sat;
    }

    int prox = 1e9 + 5;
    int resp = 0;

    if (l[n - 1] >= ((n + 1)/ 2)) {
        prox = (n + 1) / 2;
        resp = n;
    }

    if (r[0] >= ((n + 1) / 2)) {
        prox = (n + 1) / 2;
        resp = 0;
    }

    for (int i=0; i < n - 1; i++) {
        int p = abs((n/2) - (i + 1));
        if (n&1 && (i + 1) > n/2) p--;
        bool c1 = l[i] >= (i + 2) / 2;
        bool c2 = r[i + 1] >= ((n - (i + 1)) + 1) / 2;
        if (c1 && c2 && p < prox)  {
            prox = p;
            resp = i + 1;
        }
    }
    cout << resp << endl;
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
