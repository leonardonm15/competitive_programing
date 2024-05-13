#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m; cin >> n >> m;
    map<int, int> map;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        map[num]++;
    }

    int mx = 0;
    for (auto [cara, f]: map) {
        mx = max(mx, f);
    }

    cout << n - mx << endl;
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
