#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define mat vector<vector<int>>

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int mod = 1e9 + 7;

mat prog = {
    {0, 1},
    {1, 1}
};

mat base = {
    {0},
    {1}
};

mat id {
    {1, 0},
    {0, 1}
};

mat operator*(mat a, mat b) {
    mat resp(a[0].size(), vector<int>(b.size()));
    for (int i=0; i < a.size(); i++) {
        for (int j=0; j < b[0].size(); j++) {
            for (int k=0; k < b.size(); k++) {
                resp[i][j] += a[i][k] * b[k][j] % mod;
                resp[i][j] %= mod;
            }
        }
    }
    return resp;
}

mat operator^(mat a, int k) {
    mat resp = id; 
    while (k) {
        if (k & 1) {
            resp = resp * a;
        }
        a = a * a;
        k >>= 1;
    }
    return resp;
}

void solve () {
    int n; cin >> n;
    if (n == 0) cout << 0 << endl;
    else if (n == 1 || n == 2) cout << 1 << endl;
    else {
        mat resp = prog ^ n;
        resp = resp * base;
        cout << resp[0][0] << endl;
        /* cout << resp[1][0] << endl; */
    }
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
