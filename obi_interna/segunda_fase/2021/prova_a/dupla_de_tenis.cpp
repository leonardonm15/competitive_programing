#include <bits/stdc++.h>

using namespace std;
//#define int long long
#define MAXI 2e4 + 4

void solve () {
    vector<int> arr;
    for (int i=0; i < 4; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int t1 = arr[0] + arr[3];
    int t2 = arr[1] + arr[2];
    if (t1 - t2 < 0) cout << t2 - t1 << endl;
    else cout << t1 - t2 << endl;
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

