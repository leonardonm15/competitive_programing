#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, s, m; cin >> n >> s >> m;
    vector<pair<int, int>> arr(n);

    int now = 0;
    bool can = false;

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        if (l - now >= s) can = true;
        now = r;
    }

    if (m - now >= s) can = true;

    cout << (can ? "YES" : "NO") << endl;
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
