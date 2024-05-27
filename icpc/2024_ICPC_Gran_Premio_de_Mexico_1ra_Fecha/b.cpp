#include <bits/stdc++.h>

using namespace std;
#define int long long
#define mat vector<vector<int>>

const int mod = 1e9 + 7;

mat step;
mat base;

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

void cl() {
    mat k;
    k.push_back({1});
    for (int i=0; i < 19; i++) k.push_back({0});
    base = k;
    mat q;
    q.push_back({0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0});
    for (int i=0; i < 19; i++) {
        vector<int> p(20);
        p[i] ^= 1;
        q.push_back(p);
    }

    step = q;
}

void solve() {
    int n; cin >> n;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        cl();
        mat prod = step ^ num;
        prod = prod * base;
        int resp = 0;
        for (auto v: prod) {
            for (auto cara: v) {
                resp += cara;
                resp %= mod;
            }
        }

        cout << resp << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
