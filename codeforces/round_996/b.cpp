#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int MAX = 1e18;

void solve () {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int negatives = 0;
    int val = 0;
    int min_positive = MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] - b[i] < 0) {
            negatives++;
            val = a[i] - b[i];
        }
        else {
            min_positive = min(min_positive, a[i] - b[i]);
        }
    }

    if (negatives > 1) cout << "NO" << endl;
    else cout << (abs(val) <= min_positive ? "YES" : "NO") << endl;
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
