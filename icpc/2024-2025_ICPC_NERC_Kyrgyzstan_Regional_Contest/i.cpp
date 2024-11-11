#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, d; cin >> n >> d;
    vector<int> arr(n);

    for (int i = 0; i < d; i++) {
        int l, r; cin >> l >> r;
        l--;
        r--;

        arr[l]++;
        arr[r]++;
    }


    for 
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
