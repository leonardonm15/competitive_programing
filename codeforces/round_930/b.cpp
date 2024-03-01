#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int inf = 1e9 + 5;
    vector<vector<int>> nz(2, vector<int> (n, inf));
    string s; cin >> s;
    string c; cin >> c;

    bool flag = false;
    int nzs = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            nzs++;
            nz[0][i] = 0;
            flag = true;
        }
        if (s[i] == '1' && flag) nz[0][i] = nz[0][i + 1] + 1;
    }

    flag = false;
    int nzc = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (c[i] == '0') {
            nzc++;
            nz[1][i] = 0;
            flag = true;
        }
        if (c[i] == '1' && flag) nz[1][i] = nz[1][i + 1] + 1;
    }

    for (auto cara: nz) {
        for (auto c: cara) cout << c << " ";
        cout << endl;
    }

    string resp;
    flag = false;
    int counter = 1;
    for (int i=0; i < n; i++) {
        if (nz[1][i] == nz[0][i] && c[i] == s[i]) {
            counter++;
        }
        if (nz[1][i] < nz[0][i]) {
            resp.push_back(s[i]);
            resp.push_back(c[i]);
            flag = true;
        } else if (!flag && nz[0][i] >= nz[1][i]) {
            resp.push_back(s[i]);
        } else if (flag) {
            resp.push_back(c[i]);
        } else if (!flag && i == n - 1) {
            resp.push_back(s[i]);
            resp.push_back(c[i]);
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
