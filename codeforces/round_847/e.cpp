#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    int aux = n;
    int a = 0;
    int b = 0;
    vector<int> arr;
    int i = 0;
    while (n > 0) {
        arr.push_back(n&1);
        n >>= 1;
    }
    for (auto cara: arr) cout << cara;
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
