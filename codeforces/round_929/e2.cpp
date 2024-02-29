#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int gauss(int d, int u) {
    // ((primeiro termo + último termo) * número de termos) / 2
    if (d > (u + 1)) {
        int a = ((0 + u) * (u + 1)) / 2;
        int pt = d - (u + 1);
        int b = ((1 + pt) * (pt)) / 2;
        return a - b;
    } else {
        int pt = max(0ll, u - d); // 8 - 8
        int a = ((pt + u) * ((u + 1) - pt)) / 2;
        return a;
    }
}


void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> pref;
    int sum = 0;

    pref.push_back(0);
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        pref.push_back(sum);
    }

    /* cout << "pref -> "; */
    /* for (auto cara: pref) cout << cara << " "; */
    /* cout << endl; */

    int q; cin >> q;
    while (q--) {
        int l, u; cin >> l >> u;
        auto lidx = lower_bound(pref.begin(), pref.end(), *(--(upper_bound(pref.begin(), pref.end(), pref[l - 1] + u))));
        auto uidx = upper_bound(pref.begin(), pref.end(), pref[l - 1] + u);
        int a, b;
        if (lidx == pref.end()) {
            a = l;
        } else if (lidx != pref.end()) {
            a = lidx - pref.begin();
        }
        if (uidx == pref.end()) {
            b = l;
        } else if (uidx != pref.begin()) {
            b = uidx - pref.begin();
        }

        int c = gauss(max(arr[max(0ll, a - 1)], pref[a] - pref[l - 1]), u);
        int d = gauss(max(arr[max(0ll, b - 1)], pref[b] - pref[l - 1]), u);
        /* cout << "------------" << endl; */
        /* cout << "lower_bound -> " << pref[a] << endl; */
        /* cout << "quantos eu peguei  -> " << pref[a] - pref[l - 1] << endl; */
        /* cout << "quantos eu peguei 2 -> " << pref[b] - pref[l - 1] << endl; */
        /* cout << "max -> " << pref[l - 1] + u << endl; */
        /* cout << "l - r - v -> " << l << " " << a << " " << c << endl; */
        /* cout << "l - r - v -> " << l << " " << b << " " << d << endl; */
        if (d > c) cout << b << " ";
        else cout << a << " ";
    }
    cout << endl;
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
