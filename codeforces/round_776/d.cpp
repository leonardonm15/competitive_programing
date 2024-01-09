#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n + 1);
    vector<int> resp(n);
    for (int i=1; i <= n; i++) cin >> arr[i];

    for (int i=n; i > 1; i--) {
        if (arr[i] != i) {
            int dist = 0;
            while (arr[++dist] != i);
            while (dist--) {
                arr.insert(arr.begin() + i + 1, arr[1]);
                arr.erase(arr.begin());
                resp[i - 1]++;
            }
        }
    }

    for (auto c: resp) cout << c << " ";
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
