#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> resp;
    for (int i=0; i < n; i++) cin >> arr[i];
    if (arr.size() == 1) {
        cout << 1 << endl;
        cout << arr[0] << endl;
        return;
    }
    for (int i=1; i <= n; i++) {
        resp.push_back(arr[i - 1]);
        if (i < n && arr[i - 1] > arr[i]) {
            resp.push_back(1);
        }
    }
    cout << resp.size() << endl;
    for (auto cara: resp) cout << cara << " ";
    cout << endl;
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
