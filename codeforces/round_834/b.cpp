#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(51);
    int maxn = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        maxn = max(maxn, num);
        arr[num]++;
    }
    int resp = 0;
    int i=1;
    while (i <= maxn) {
        if (!arr[i]) resp += i;
        i++;
    }
    if (resp == k) {
        cout << "YES" << endl;
    } else {
        while (resp < k) {
            resp += i;
            i++;
        }
        if (resp == k) cout << "YES" << endl;
        else cout << "NO" << endl;
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
