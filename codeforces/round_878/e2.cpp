#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    vector<string> s(2);
    cin >> s[0] >> s[1];
    int t, q; cin >> t >> q;

    vector<int> diff(s[0].size());
        vector<int> ops(q + 5);
    int curr = 0;
    for (int i=0; i < (int) s[0].size(); i++) {
        if (s[0][i] != s[1][i]) {
            diff[i]++;
            curr++;
        }
    }

    for (int i=0; i < q; i++) {
        int tq; cin >> tq;
        curr += ops[i];
        if (tq == 3) {
            cout << (curr ? "NO" : "YES") << endl;
        }
        if (tq == 2) {
            int i, j, u, v; cin >> i >> j >> u >> v;
            i--; j--; u--; v--;
            swap(s[i][j], s[u][v]);
            if (s[0][j] != s[1][j] && diff[j] == 0) {
                diff[j] = 1;
                curr++;
            }
            if (s[0][v] != s[1][v] && diff[v] == 0) {
                diff[v] = 1;
                curr++;
            }
            if (s[0][j] == s[1][j] && diff[j] == 1) {
                diff[j] = 0;
                curr--;
            }
            if (s[0][v] == s[1][v] && diff[v] == 1) {
                diff[v] = 0;
                curr--;
            }
        }
        if (tq == 1) {
            int pos; cin >> pos; pos--;
            if (diff[pos]) {
                curr--;
                if (i + t < q) ops[i + t]++;
            }
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
