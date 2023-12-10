#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define int long long

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	int soma = 0;
	int m = 1e18;
	for (int i=0; i < n; i++) {
		int num; cin >> num;
		arr[i] = num;
		m = min(num, m);
	}

	for (auto cara: arr) {
		if (cara > m) soma += (cara - m);
	}
	cout << soma << endl;
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

