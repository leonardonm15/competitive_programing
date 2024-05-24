#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> tow(n);
    vector<int> vis(n);
    
    for (int i=0; i < n; i++) cin >> tow[i];

    for (int i=2; i < n; i++) {
        if (tow[i] && tow[i - 1] && !vis[i] && !vis[i - 1]) {
            vis[i]++;
            vis[i - 1]++;
            i += 2;
        }
    }


    for (int i=1; i < n; i++) {
        if (tow[i]) {
            bool f1 = false;
            bool f2 = false;
            if (i == n - 1 || !vis[i + 1]) f1 = true;
            if (!vis[i - 1]) f2 = true;

            if (f1 && f2) vis[i]++;
        }
    }

    /* cout << "vis -> "; */
    /* for (int i=0; i < n; i++) cout << vis[i] << " "; */
    /* cout << endl; */

    int resp = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && tow[i]) resp++;
    }

    /* cout << "vis -> "; */
    /* for (int i=0; i < n; i++) cout << vis[i] << " "; */
    /* cout << endl; */

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
