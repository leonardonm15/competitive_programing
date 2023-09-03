#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    n--;
    vector<int> arr;
    for (int i=2; i * i<n; i++){ 
        if (n % i == 0) {
            arr.push_back(i);
            arr.push_back(n/i);
        }
    }
    /* cout << "arr size -> " << arr.size() << endl; */
    for (auto num: arr) {
        /* cout << "num -> " << num << endl; */
        int i = 1;
        int sum = 1;
        while (sum < n) {
            sum += pow(num, i);
            i++;
        }
        /* cout << "sum -> " << sum << endl; */

        if (sum == n + 1) {
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
