#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n + 1);
    int sum = 0;
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        sum += num;
        arr[i] = sum;
    }
    for (int i=1; i <= n; i++) {
        int num = sum - arr[i];
        if (num % 2 == 0 && arr[i] % 2 == 0) {
            cout << "YES" << endl;
            return;
        }else if (num % 2 == 1 && arr[i] % 2 == 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
