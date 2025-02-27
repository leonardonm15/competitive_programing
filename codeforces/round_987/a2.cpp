#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr[num]++;
    }

    sort(arr.rbegin(), arr.rend());

    cout << n - arr[0] << endl;
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
