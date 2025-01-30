#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;

    vector<int> arr(n + 1);

    if ((n < 26 && n&1)) {
        cout << -1 << endl;
        return;
    }

    if (n >= 26 && n&1) {
        arr[27]++;
        arr[27 - 9]++;
        arr[27 - 25]++;

        arr[1] = 1e6 - 1;
        arr[5] = 1e6 - 1;
    }

    int k = 4;
    for (int i = 1; i <= n; i++) {
        if (!arr[i]) {
            arr[i] = k / 2;
            k++;
        }
    }

    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;
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
