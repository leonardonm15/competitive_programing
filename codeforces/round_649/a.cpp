#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> pos;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if ((num % k) == 0) {
            pos.push_back(i);
        }
    }

    if (!pos.size()) {
        cout << n << endl;
    } else if (pos.size() == arr.size()) {
        cout << -1 << endl;
    } else if (pos.size() == 1) {
        cout << max((n - 1) - pos[0] - 1, pos[0]) << endl;
    } else {
        int resp = 0;
        for (int i=1; i < (int)pos.size() - 1; i++) {
            resp = max(resp, pos[i] - pos[i - 1] - 1);
        }

        cout << (resp ? resp : -1) << endl;
    }

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
