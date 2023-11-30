#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    map<char, int> map;
    map['D'] = 1;
    map['U'] = -1;
    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i=0; i < n; i++) {
        int k; string s; cin >> k >> s;
        for (auto cara: s) {
            if (arr[i] == 0 && map[cara] == -1) arr[i] = 9;
            else arr[i] = (abs(arr[i] + map[cara])) % 10;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
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
