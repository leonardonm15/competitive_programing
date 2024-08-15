#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> h(n);
    vector<int> d(n - 1);

    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n - 1; i++) cin >> d[i];

    int lenth = 0;
    int flag = true;
    for (int i = 1; i < n; i++) {
        int hd = h[i - 1];
        int dd = d[i - 1];

        if (max(lenth, hd) > dd) {
            lenth = max({lenth - dd, 0ll, hd - dd});
        } else {
            flag = false;
            break;
        }
    }

    reverse(d.begin(), d.end());
    reverse(h.begin(), h.end());

    lenth = 0;
    bool flag2 = true;
    for (int i = 1; i < n; i++) {
        int hd = h[i - 1];
        int dd = d[i - 1];

        if (max(lenth, hd) > dd) {
            lenth = max({lenth - dd, 0ll, hd - dd});
        } else {
            flag2 = false;
            break;
        }
    }

    cout << ((flag | flag2) ? "habibi" : "which") << endl;
}

signed main() {
    int t; cin >> t;
    while (t--) solve();
}
