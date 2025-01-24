#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr;
    arr.push_back(1);
    for (int i = 1; i <= n / 2; i++) {
        arr.push_back(i);
    }

    for (int i = 1; i < (n + 1) / 2; i++) {
        arr.push_back(i);
    }

    for (auto c: arr) cout << c << " ";
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
