#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int ans = 1;
    for (int i=1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int a = i;
            int b = j;
            int resp = 0;
            for (int k = 0; k < n; k++) {
                if (arr[k] == a) {
                    resp++;
                    swap(a, b);
                }
            }
            ans = max(ans, resp);
        }
    }

    cout << ans << endl;
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
