#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    bool flag = false;
    int resp = 0;
    for (int i=0; i < n; i++) {
        if (arr[i] && !flag) flag = true;
        if (!arr[i] && flag) resp++;
    }

    for (int i=n - 1; i >= 0; i--) {
        if (!arr[i]) resp--;
        else break;
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
