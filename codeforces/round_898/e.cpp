#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, h; cin >> n >> h;
    vector<int> arr;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }
    int l = 0;
    int r = 5e9 + 3;
    int mid;
    int diff;
    int resp = 0;
    while (l < r) {
        diff = 0;
        mid = (l + r) / 2;
        for (int i=0; i < n; i++) {
            int num = mid - arr[i];
            if (num > 0) diff += num;
        }
        if (diff == h) {
            resp = mid;
            break;
        }
        if (diff >= h) {
            r = mid;
        } else if (diff < h) {
            l = mid + 1;
            resp = mid;
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

