#include <bits/stdc++.h>

using namespace std;

#define edl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());

    if (n <= 2) {
        cout << -1 << endl;
        return;
    }
    
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] * n * 2 < sum) c++;
    }

    if (c > n / 2) {
        cout << 0 << endl;
        return;
    }

    int k = arr[n / 2];
    int resp = (k * 2 * n) - sum;
    cout << resp + 1 << endl;

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
