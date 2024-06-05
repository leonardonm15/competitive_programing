#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> freq(26);
	vector<int> arr(n);
	for (int i=0; i < n; i++) {
		cin >> arr[i];
	}

	char nc = 'a';
	string resp;
	for (int i=0; i < n; i++) {
		for (int j=0; j < 26; j++) {
			if (arr[i] == freq[j]) {
				resp.push_back('a' + j);
				freq[j]++;
				break;
			}

		}
	}

	cout << resp << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
