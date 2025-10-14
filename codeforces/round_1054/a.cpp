#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int neg = 0;
    int pos = 0;
    int zer = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) neg++;
        if (arr[i] > 0) pos++;
        if (arr[i] == 0) zer++;
    }

    if (neg%2 == 1) cout << zer + 2 << endl;
    else cout << zer << endl;
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
