#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    string arr; cin >> arr;
    for (int i=0; i < n; i++) {
        while (arr[i + 1] == arr[i]) i++;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
