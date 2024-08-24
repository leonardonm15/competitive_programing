#include <bits/stdc++.h>

using namespacestd;

#define endl '\n'
// #define int long long

void solve() {
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int resp = 0;
    for (auto c: arr) {
        if (c == 0) continue;
        if (c == 1) resp = max(resp, 1);
        else if (c % 2 == 0) resp = max(resp, 1);
        else if (c % 2 == 1) resp = 2;
    }

    cout << resp << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
