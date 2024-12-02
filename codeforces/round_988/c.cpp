#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;

    if (n <= 4) {
        cout << -1 << endl;
        return;
    }

    vector<int> arr;
    for (int i = 1; i <= n; i += 2) {
        if (i == 5) continue;
        arr.push_back(i);
    }

    arr.push_back(5);
    arr.push_back(4);

    for (int i = 2; i <= n; i+= 2) {
        if (i == 4) continue;
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
