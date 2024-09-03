#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int resp = 1e18;
int check(int mid, int base, int nk) {
    int p1 = ((1 + mid) * mid) / 2;
    int p2 = nk - p1;
    p1 -= base;
    cout << "------------------" << endl;
    cout << "Mid -> " << mid << endl;
    cout << "p1 -> " << p1 << endl;
    cout << "p2 -> " << p2 << endl;
    resp = min(resp, abs(p1 - p2));
    return abs(p1 - p2);
}

void solve () {
    int n, k; cin >> n >> k;

    int base = (k * (k - 1)) / 2; // começo da pa
    int total = ((1 + n + k) * (n + k)) / 2;

    int l = k;
    int r = n + k;
    int i = 10;
    while (i--) {
        int step = (l + r) / 3;
        int mid1 = min(n + k, l + step);
        int mid2 = max(k, r - step);
        cout << "----------------------------" << endl;
        if (check(mid1, base, total) <= check(mid2, base, total)) r = mid2;
        else l = mid1;
    }

    cout << resp << endl;
    /* cout << l << endl; */
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
