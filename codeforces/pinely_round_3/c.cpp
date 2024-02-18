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
    vector<int> c(n);

    for (int i=0; i < n; i++) cin >> l[i];
    for (int i=0; i < n; i++) cin >> r[i];
    for (int i=0; i < n; i++) cin >> c[i];

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    vector<int> diff;

    for (int i=0; i < n; i++) {
        auto p = upper_bound(l.begin(), l.end(), r[i]);
        int idx = p - l.begin();
        int u;
        if ((idx - 1) >= 0) u = r[i] - l[idx - 1];
        else u = r[i] - l[idx];
        diff.push_back(u);
        if (p == l.end()) l.erase(p - 1);
        else l.erase(p);
    }

    /* for (int i=0; i < n; i++) { */
    /*     int u = r[i] - l[i]; */
    /*     diff.push_back(u); */
    /* } */

    sort(diff.begin(), diff.end());

    /* cout << "diff -> "; */
    /* for (auto cara: diff) cout << cara << " "; */
    /* cout << endl; */
    /* return; */

    sort(c.rbegin(), c.rend());

    int resp = 0;
    for (int i=0; i < n; i++) {
        resp += (diff[i] * c[i]);
        /* cout << resp << endl; */
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
