#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int resp = 1e9;
    for (int i = 1; i < n; i += 2) {
       if (arr[i] != ((i + 1) / 2)) resp = min(resp, (i + 1) / 2);
    }

    /* cout << resp << endl; */

    for (int i = 2; i < n; i += 2) {
        if (arr[i] != (i / 2) + 1) resp = min(resp, (i / 2));
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
