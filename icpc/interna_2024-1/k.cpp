#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long
#define mat vector<vector<int>>
const int zap = 998244353;

mat operator*(mat a, mat b) {
    mat res(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                res[i][j] += a[i][k] * b[k][j] % (zap - 1);
                res[i][j] %= (zap - 1);
            }
        }
    }
    return res;
}

mat operator^(mat a, int k) {
    mat res(a.size(), vector<int>(a.size()));
    for (int i = 0; i < a.size(); i++) {
        res[i][i] = 1;
    }

    while (k) {
        if (k & 1) {
            res = res * a;
        }

        a = a * a;
        k >>= 1;
    }

    return res;
}

int bpow(int a, int exp) {
    int resp = 1;
    while (exp) {
        if (exp&1) {
            resp *= a;
            resp %= zap;
        }
        a *= a;
        a %= zap;
        exp >>= 1;
    }

    return resp;
}

mat step = {
    {0, 1},
    {1, 1}
};

mat fib = {
    {0},
    {1}
};

void solve () {
    int n; cin >> n;

    mat prod = step ^ n;
    prod = prod * fib;

    cout << bpow(2,prod[0][0]) << endl;
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
