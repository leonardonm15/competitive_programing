#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
	int n, k; cin >> n >> k;
	vector<int> arr(n);
	vector<int> sarr(n);

	for (int i=0; i < n; i++) {
		int num; cin >> num;
		arr[i] = num;
		sarr[i] = num;
	}

	sort(sarr.begin(), sarr.end());
	if (k == 1 && sarr != arr) cout << "NO" << endl;
	else cout << "YES" << endl;

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


