#include <bits/stdc++.h>

using namespace std;
#define int long long 

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> pref;
    vector<int> vis(n + 1);
    vector<int> extras;
    int last = 0;
    bool flag = false;
    for (int i=0; i < n - 1; i++) {
        cin >> arr[i];
        int k = arr[i] - last;
        if (k > 0 && k <= n && !vis[k]) vis[k]++;
        else {
            if (k == 1) flag = true;
            extras.push_back(k);
        }
        pref.push_back(k);
        last = arr[i];
    }
    if (flag) {
        cout << "NO" << endl;
        return;
    }

    sort(extras.rbegin(), extras.rend());

    int c = 0;
    vis[0]++;
    for (auto cara: extras) {
        for (int i=n; i > 1; i--){
            int k = cara - i;
            if (k <= n && (!vis[i] && !vis[cara - i])) {
                vis[i]++;
                vis[cara - i]++;
                c++;
                break;
            }
        } 
    }

    int p = 0;
    for (int i=1; i <= n; i++) {
        if (!vis[i]) {
            p++;
        }
    }

    if ((c >= extras.size()) && p <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
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
