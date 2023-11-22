#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    //  se eu colocar todos os segmentos que tem ele e ele for o maior cara do
    //  array quer dizer que da 
    vector<int> arr(100);
    for (int i=0; i < n; i++) {
        int l, r; cin >> l >> r;
        if (k >= l && k <= r) {
            for (l; l <= r; l++) arr[l]++;
        }
    }
    for (int i=0; i < 100; i++) {
        if (arr[i] == arr[k] && i != k) {
            cout << "NO" << endl;
            return;
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
