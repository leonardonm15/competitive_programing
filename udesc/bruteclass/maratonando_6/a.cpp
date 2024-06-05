#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
	int n, x, y; cin >> n >> x >> y;
	map<pair<int, int>, int> mod;

	int resp = 0;
	for (int i=0; i < n; i++) {
		int num; cin >> num;
		int xq = (x - num % x) % x;
		int yq = num % y;
		pair<int, int> v = {num % x, num % y};
		pair<int, int> a = {xq, yq};
		resp += mod[a];
		mod[v]++;
	}

	cout << resp << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
