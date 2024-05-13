#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool check(int mid, vector<int>& arr, int k) {
    int n = arr.size();
    for (int i=0; i < n; i++) {
        k -= max(0ll, arr[i] - mid);
    }
    
    return k >= 0;
}

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    int mx = 0;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    int l = 0;
    int r = mx;
    int resp = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, arr, k)) {
            resp = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << resp << endl;
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
