#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> map;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        map[arr[i]]++;
    }

    int resp = 0;
    if (map[1] > 1) resp += map[1];
    if (map[2] > 1) resp += map[2];

    for (int i=0; i < n; i++) {
        if (arr[i] == 1 && map[2] > 0) resp += map[2];
        else if (arr[i] == 2 && map[1] > 0) resp += map[1];
        else if (map[arr[i]] > 0 && arr[i] != 1 && arr[i] != 2) resp += map[arr[i]];
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
