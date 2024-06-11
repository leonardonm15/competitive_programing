#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    map<int, int> ns;
    map<int, int> lo;
    map<tuple<int, int, char>, int> diag;
    vector<pair<int, int>> pos;

    for (int i=0; i < n; i++) {
        int x, y; cin >> x >> y;
        ns[x]++;
        lo[y]++;
        pos.push_back({x, y});
        diag[{x - y, 0, 'A'}]++;
        diag[{x + y, 0, 'B'}]++;
    }

    int resp = 0;
    for (auto [x, y] : pos) {
        resp += ns[x] - 1;
        resp += lo[y] - 1;
        resp += diag[{x - y, 0, 'A'}] - 1;
        resp += diag[{x + y, 0, 'B'}] - 1;
    }

    cout << resp << endl;
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
