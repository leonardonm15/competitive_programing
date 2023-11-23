#include <bits/stdc++.h>

using namespace std;
//#define int long long

bool is_sorted(vector<int> arr) {
    int n = arr.size(); 
    for (int i=0; i < n - 1; i++) {
        if (arr[i + 1] < arr[i]) return false;
    }
    return true;
}

void solve () {
    int n; cin >> n;
    multiset<int> s;
    vector<int> arr(n);
    int m = 0;
    int nm = 0;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (num == m) nm++;
        if (num < m) {
            m = num;
            nm = 1;
        }
    }
    if (nm > 1 && is_sorted(arr)) {
        cout << 0 << endl;
        return;
    }
    

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
