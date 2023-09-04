#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 2e5 + 5;
vector<int> arr(maxn);

void solve () {
	int n; cin >> n;
	for (int i=0; i < n - 1; i++) {
		int num; cin >> num;
		arr[num]++;
	}
	for (int i=1; i <= n; i++) {
		if (arr[i] == 0) {
			cout << i << endl;
			break;
		}
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
