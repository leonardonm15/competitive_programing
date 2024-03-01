#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int gauss(int u, int v) { // quantidade de termos
    int g = (u + u - v + 1) * v / 2;
    return g;
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

    int q; cin >> q;
    int ri = -1;
    int resp = 0;
    int l, u;
    while (q--) {
        cin >> l >> u;
        ri = -1;
        resp = 0;
        int uidx = (--(upper_bound(pref.begin(), pref.end(), pref[l - 1] + u))) - pref.begin();
        for (int i = max(l, uidx - 10); i <= min((int)pref.size() - 1, uidx + 10); i++) {
            int a = pref[i] - pref[l - 1];
            int g = gauss(u, a);
            if (g > resp || ri == -1) {
                resp = g;
                ri = i;
            }
        }
        cout << max(ri, l) << " ";
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
