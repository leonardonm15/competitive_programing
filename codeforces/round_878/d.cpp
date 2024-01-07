#include <bits/stdc++.h>

using namespace std;
#define int long long

bool check(vector<int> &arr, int mid) {
    int n = arr.size();
    int i = 0;

    int range = arr[0] + mid;
    while (i < n && arr[i] - range <= mid) i++;

    range = arr[i] + mid;
    while (i < n && arr[i] - range <= mid) i++;

    range = arr[i] + mid;
    while (i < n && arr[i] - range <= mid) i++;

    return (i == n);
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    /* arr.erase(unique(arr.begin(), arr.end())); */
    
    int l = 0;
    int r = 1e9;
    int resp;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(arr, mid)) {
            resp = mid;
            r = mid - 1;
        } 
        else {
            l = mid + 1;
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
