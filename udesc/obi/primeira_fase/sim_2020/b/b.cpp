#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(4);
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[num]++;
    }
    int p, m; cin >> p >> m;
    arr[1] -= p;
    arr[2] -= m;
    if (arr[1] > 0 || arr[2] > 0) cout << "N" << endl;
    else cout << "S" << endl;
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
