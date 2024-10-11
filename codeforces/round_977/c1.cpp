#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m, q; cin >> n >> m >> q;
    vector<pair<int, int>> arr(n); // after i see one guy i can reorder him wherever i want
    vector<int> s(m);

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr[i] = {num, i};
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        s[i] = arr[num - 1].second;
    }

    int mx = -1;
    bool flag = false;
    for (auto c: s) {
        if (c <= mx) continue;
        if (c > mx && c == mx + 1) {
            mx = c;
        } else {
            flag = true;
        }
    }

    cout << (flag ? "TIDAK" : "YA") << endl;
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
