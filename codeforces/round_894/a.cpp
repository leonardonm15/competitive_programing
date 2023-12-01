#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, m; cin >> n >> m;
    int c = 0;
    string v = "vika";
    bool flag = false;
    vector<string> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    c = 0;
    for (int i=0; i < m; i++) {
        bool flg = false;
        for (int j=0; j < n; j++) {
            if (!flg && arr[j][i] == v[c]) {
                /* cout << arr[j][i] << endl; */
                c++;
                flg = true;
            }
        }
    }
    if (c > 3) cout << "YES" << endl;
    else cout << "NO" << endl;
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
