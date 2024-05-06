#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    int c = 0;
    for (int i=1; i < n - 1; i++) {
        if (c == n + 1) break;
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            swap(arr[i + 1], arr[i]);
            i = 1;
            c++;
        }
    }

    if (c == n + 1) cout << "NO" << endl;
    else cout << "YES" << endl;
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
