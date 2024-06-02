#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    map<int, int> map;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        map[num]++;
    }

    int resp = 0;
    for (auto [c, v]: map) resp += (v / 3);

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
