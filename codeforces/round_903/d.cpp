#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    int resp = 1; cin >> resp;
    int k = 0;
    for (int i=0; i < n - 1; i++) {
        int num; cin >> num;
        resp *= num;
    }
    k = resp;
    k = pow(k, (1.0/n));
    k = pow(k, n);
    /* cout << k << endl; */
    /* cout << num << endl; */
    /* cout << resp << endl; */
    if (resp == k) cout << "YES" << endl;
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
