#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int robin = 0;
    int resp = 0;

    for (auto c: arr) {
        if (c >= k) {
            robin += c;
        }

        if (c == 0 && robin > 0) {
            robin--;
            resp++;
        }
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
