#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n), c(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) if (arr[i] == -1) {
        arr[i] = 0;
        c[i] = 1;
    }

    int score = 0;
    for (int i = 0; i < n - 1; i++) {
        score += arr[i + 1] - arr[i];
    }

    /* cout << "socore -> " << score << endl; */

    if (c[n - 1] && score < 0) {
        arr[n - 1] = abs(score);
    } else if (c[0] && score > 0) {
        arr[0] = score;
    }

    int ns = 0;
    for (int i = 0; i < n - 1; i++) {
        ns += arr[i + 1] - arr[i];
    }

    cout << abs(ns) << endl;
    for (auto v: arr) cout << v << " ";
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
