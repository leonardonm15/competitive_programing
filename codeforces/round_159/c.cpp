#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> r;
    int c = -1e9 - 1;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        a[i] = num;
        c = max(c, num);
    }

    if (a.size() == 1) {
        cout << 1 << endl;
        return;
    }

    for (int i=0; i < n; i++) {
        if (c - a[i] > 0) r.push_back(c - a[i]);
    }

    int g = r[0];
    for (int i=1; i < n - 1; i++) {
        g = gcd(g, r[i]);
    }

    int resp = 0;
    for (auto cara: r) {
        resp += cara / g;
    }

    sort(a.rbegin(), a.rend());
    int k = 1;
    for (int i=0; i < n; i++) {
        if (a[i] == (c - (g * k))) k++;
    }

    int v = abs((c - (c - (g * k))) / g);
    resp += v;
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
