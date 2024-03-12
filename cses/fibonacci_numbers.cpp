#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define mat vector<vector<int>>;

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
    mat resp(b.size(), vector<int> b[0].size());
    for (int i=0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            resp[i][0] += (a[i][j] * b[j][0]) % mod;
        }
    }
    return resp;
}

void solve () {
    int n; cin >> n;
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
