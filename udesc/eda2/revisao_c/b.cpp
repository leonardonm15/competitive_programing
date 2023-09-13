#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    int k = 1;
    vector<int> arr;
    for (int i=0; i < n; i++) {
       int num; cin >> num;
       arr.push_back(num);
       k *= num;
    }
    for (auto num: arr) {
        cout << k / num << " ";
    }
    cout << endl;
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
