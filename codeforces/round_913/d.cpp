#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> q;
	// q.push_back({0, 0});
	for (int i=0; i < n; i++) {
		int l, r; cin >> l >> r;
		q.push_back({l, r});
	}

	int e = 0;
	int d = 2e9;
	int mid = (e + d) / 2;
	int atual = 0;
	int answ = 0;

	while (e <= d) {
		bool flag = false;
		for (auto [l, r]: q) {
			if (l > atual) {
				if ((atual + mid) > r) atual = r;
				else if ((atual + mid) <= r && (atual + mid) >= l) atual = atual + mid;
				else if (atual + mid < l) {
					// se o range nao é o suficiente aumenta o range
					e = mid + 1;
					mid = (e + d) / 2;
					flag = true;
					break;
				}
			}
			if (r < atual) {
				if ((max(atual - mid, 0)) < l) atual = l;
				else if (max(atual - mid, 0) <= r …
#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> q;
	// q.push_back({0, 0});
	for (int i=0; i < n; i++) {
		int l, r; cin >> l >> r;
		q.push_back({l, r});
	}

	int e = 0;
	int d = 2e9;
	int mid = (e + d) / 2;
	int atual = 0;
	int answ = 0;

	while (e <= d) {
		bool flag = false;
		for (auto [l, r]: q) {
			if (l > atual) {
				if ((atual + mid) > r) atual = r;
				else if ((atual + mid) <= r && (atual + mid) >= l) atual = atual + mid;
				else if (atual + mid < l) {
					// se o range nao é o suficiente aumenta o range
					e = mid + 1;
					mid = (e + d) / 2;
					flag = true;
					break;
				}
			}
			if (r < atual) {
				if ((max(atual - mid, 0)) < l) atual = l;
				else if (max(atual - mid, 0) <= r && max(atual - mid, 0) >= l) atual = max(atual - mid, 0);
				else if (max(atual - mid, 0) > r) {
					e = mid + 1;
					mid = (e + d) / 2;
					flag = true;
					break;
				}
			
			}
		}
		if (!flag) {
			answ = mid;
			d = mid - 1;
			mid = (e + d) / 2;
		}
	}
	cout << answ << endl;
}

int main() {
	int TC; cin >> TC;
	while (TC--) solve();
}
