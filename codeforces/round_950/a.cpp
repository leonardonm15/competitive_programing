#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m; cin >> n >> m;
    map<char, int> map;
    for (int i=0; i < n; i++) {
        char a; cin >> a;
        map[a]++;
    }

    int resp = 0;
    for (int i=0; i < 7; i++) {
        if (map['A' + i] < m) resp += (m - map['A' + i]);
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
