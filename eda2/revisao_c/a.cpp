#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    map<int, int> map;
    vector<int> arr;
    int n, k; cin >> n >> k;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
        map[num]++;
    }
    for (auto num: arr) {
        if (map[k - num] > 0) {
            cout << "TEM" << endl;
            return;
        }
    }
    cout << "NAO TEM" << endl;
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
