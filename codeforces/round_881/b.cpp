#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    
    int resp = 0;
    int op = 0;
    int r = 0;
    while (r < n) {
        if (arr[r] < 0) {
            op++;
            while (arr[r] <= 0 && r < n) {
                r++;
            }
        } else r++;
    }

    for (auto cara: arr) resp += abs(cara);
    cout << resp << " " << op << endl;
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
