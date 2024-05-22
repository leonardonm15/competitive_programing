#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < m; i++) cin >> b[i];
    
    vector<int> vis(n);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int resp = 0;
    
    for (int i=0; i < m; i++) {
        bool flag = false;
        for (int j=0; j < n; j++) {
            if ((b[i] <= a[i] + k || b[i] >= a[i] - k) && !vis[j]) {
                vis[j]++;
                resp++;
            }
        }
    }

    /* for (int i=0; i < n; i++) if (vis[i]) resp++; */
    cout << resp << endl;

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
