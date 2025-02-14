#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long

vector<vector<int>> arr;

void solve () {
	int n, m; cin >> n >> m;
	arr.resize(n, vector<int>(m));

	vector<pair<int, int>> soma(n);

	for (int i = 0; i < n; i++) {
		int s = 0;
		soma[i].second = i;
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			s += arr[i][j];
		}

		soma[i].first = s;
	}

	sort(soma.rbegin(), soma.rend());

    /* cout << "--------------" << endl; */
    /* for (auto [f, s]: soma) { */
    /*     cout << f << " " << s << endl; */
    /* } */

	vector<int> v;

    for (auto [f, s]: soma) {
        for (auto c: arr[s]) {
            v.push_back(c);
        }
    }

	int resp = 0;
	for (int i = 0; i < (int) v.size(); i++) {
	    resp += (v[i] * (v.size() - i));
	}

    cout << resp << endl;

    arr.clear();
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
