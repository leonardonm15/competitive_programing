#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];


    vector<string> resp(n / k);
    for (int i = 0; i < n; i += k) {
        for (int j = 0; j < n; j += k) resp[i/k].push_back(arr[i][j]);
    }

    for (auto v: resp) {
        for (auto c: v) cout << c;
        cout << endl;
    }
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
