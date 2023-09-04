#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
	int n; cin >> n;
	cout << n << " ";
	while (n != 1) {
		if (n % 2 == 0) {
		    n /= 2;
		    cout << n << " ";
        } else {
            n *= 3;
            n++;
            cout << n << " ";
        }
	}
	cout << endl;
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
