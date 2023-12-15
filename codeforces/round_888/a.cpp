#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, m, k, h; cin >> n >> m >> k >> h;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    
    /* pra cada andar ele fica no andar e vai vendo se a diff é igual pra alguem, se for dele te o cara */
    int resp = 0;
    /* cout << "k -> " << k << endl; */
    for (int i=0; i < n; i++) {
        int d = abs(h - arr[i]);
        if (d > 0 && d % k == 0 && d / k < m) {
            /* cout << "d - > " << d << endl; */
            /* cout << "arr[i] -> " << arr[i] << endl; */
            resp++;
        }
    }
    cout << resp << endl;
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
