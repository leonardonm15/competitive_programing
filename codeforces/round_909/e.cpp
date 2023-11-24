#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 2e5 + 5;

bool is_sorted(vector<int> arr, int k) {
    int n = arr.size(); 
    for (int i=k; i < n - 1; i++) {
        if (arr[i + 1] < arr[i]) return false;
    }
    return true;
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int m = 1e10;
    int im = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;
        if (num < m) {
            m = num;
            im = i;
        }
    }
    cout << (is_sorted(arr, index_menor) ? im : -1) << endl;
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
