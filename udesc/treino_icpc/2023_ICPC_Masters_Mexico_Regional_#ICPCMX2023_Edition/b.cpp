#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define mat vector<vector<int>> 

const int mod = 1e9 + 7;

mat operator*(mat a, mat b) {
	mat resp(a.size(), vector<int>(b[0].size()));
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
	mat resp (a.size(), vector<int>(a.size()));
	for (int i=0; i < a.size(); i++) {
		resp[i][i] = 1;
	}

	while (k) {
		if (k & 1) {
			resp = resp * a;
		}

		a = a * a;
		k >>= 1;
	}

	return resp;
}

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     


mat base = {
	{3},
	{1},
	{2},
	{3}
};

mat prog = {
	{1, 0, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
	{1, 1, 2, 3},
};


void solve () {
	int n; cin >> n;
	if (n < 3) cout << n + 1 << endl;
	else {
		mat v = prog ^ n;
		v = v * base;
		cout << v[1][0] << endl;
	}
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
	if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
