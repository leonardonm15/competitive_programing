#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool check(int mid, vector<int>& a, vector<int>& c, int k) {
    int dm = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        k -= (a[i] + (((mid - 1) / c[i]) * a[i]));
        if (k <= 0) return true;
    }
    return false;
}

void solve () {
    int h, n; cin >> h >> n;
    vector<int> a(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    
    int l = 1;
    int r = 1e11;
    int resp = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, a, c, h)) {
            resp = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << resp << endl;
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
