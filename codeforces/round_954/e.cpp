#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<int> difs;
    for (int i = 1; i < n; i++) difs.push_back(arr[i] - arr[i - 1]);

    int v = 0;
    for (auto d: difs) {
        v += d;
        cout << d << " ";
    }
    cout << endl;

    sort(difs.rbegin(), difs.rend());
    if (n&1) v -= difs[0];

    cout << "v -> " << v << endl;
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
