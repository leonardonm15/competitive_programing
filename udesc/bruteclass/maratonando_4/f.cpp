#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


bool check(int mid, vector<int>& arr) {
    int dm = 0;
    int sum = 0;
    int n = arr.size();
    for (int i=0; i < n; i++) {
        if (sum + arr[i] > mid) {
            sum = arr[i];
            dm++;
        }
        else sum += arr[i];
    }
    if (dm >= 3) return false;
    else return true;
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    int l = 1;
    int r = 1e14;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, arr)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
