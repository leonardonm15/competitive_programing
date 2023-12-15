#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    map<int, int> map;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        map[arr[i]]++;
    }
    
    if (arr[0] == arr[n - 1] && map[arr[0]] >= k) {
        cout << "YES" << endl;
        return;
    }

    if (map[arr[n - 1]] < k || map[arr[0]] < k) {
        cout << "NO" << endl;
        return;
    }

    int c = 0;
    for (int i=0; i < n; i++) {
        if (arr[i] == arr[0]) c++;
        map[arr[i]]--;
        if (c == k) break;
    }

    if (map[arr[n - 1]] >= k) {
        cout << "YES" << endl;
        return;
    } else cout << "NO" << endl;
    
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
