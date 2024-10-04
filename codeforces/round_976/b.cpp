#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int rt(int a) {

    int l = 1;
    int r = a;
    int ans = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if ((4e18l / mid) <= mid || mid * mid > a) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }

    return ans;
}

bool check(int n, int mid) {
    return (mid - rt(mid)) >= n;
}

void solve () {
    int n; cin >> n;

    int l = 1;
    int r = 4e18;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(n, mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
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
