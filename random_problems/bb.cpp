#include <bits/stdc++.h>

using namespace std;
#define endl '\n' 
#define int long long

bool check(int mid, vector<int>& arr, int vida){
    int resp = 0;
    for (int i=0; i < arr.size(); i++) {
        if (i < arr.size() - 1 && mid >= arr[i + 1] - arr[i]) {
            resp += arr[i + 1] - arr[i];
        } else {
            resp += mid;
        }
    }

    return resp >= vida;
}

void solve () {
int n, k; cin >> n >> k;
    vector<int> arr(n); 
    for (int i=0; i < n; i++) cin >> arr[i];
    int l = 1;
    int r = 1e18;
    int answ = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, arr, k)) {
            answ = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << answ << endl;
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
