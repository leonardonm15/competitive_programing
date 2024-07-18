#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int SZ = 500;

void solve () {
    // mapa dos fatores primos de x
    // mapa dos fatores primos de x de cada cara
    // prefixo fatores primos 

    int n, x; cin >> n >> x;
    int xx = x;
    map<int, int> xf; // x factors
    vector<vector<int>> f(n, vector<int>(SZ));

    int d = 2;
    while (xx > 1) {
        while (xx % d == 0) {
            xx /= d;
            xf[d]++;
        }
        d++;
    }

    /* cout << "xf -> " << endl; */
    /* for (auto [d, q]: xf) { */
    /*     cout << d << " " << q << endl; */
    /* } */
    /* cout << endl; */

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (num > x) continue;
        
        for (auto [d, q]: xf) {
            while (num > 1 && num % d == 0) {
                num /= d;
                f[i][d]++;
            }
        }
    }

    for (int i = 1; i <= 7; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 7; j++) cout << f[i][j] << " ";
        cout << endl;
    }

    int resp = 1;
    vector<int> now(SZ);
    for (int i = 0; i < n; i++) {
        for (auto [d, q]: xf) {
            now[d] += f[i][d];
        }

        int bad = 0;
        for (auto [d, q]: xf) {
            if (now[d] >= q) bad++;
        }

        if (bad == (int)xf.size()) {
            resp++;
            now = f[i];
        }
    }

    int bad = 0;
    for (auto [d, q]: xf) if (now[d] >= q) bad++;
    if (bad == (int)xf.size()) resp++;

    cout << resp << endl;
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
