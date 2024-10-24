#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> vis(n);

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        num--;
        arr[i] = num;
    }

    int resp = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (arr[i] == i || arr[arr[i]] == i) {
            vis[i]++;
            vis[arr[i]]++;
        } else {
            int now = arr[i];
            int sz = 0;
            /* cout << "------------" << endl; */
            /* cout << "sc -> " << i << endl; */
            while (now != i) {
                /* cout << "now -> " << now << endl; */
                vis[now]++;
                now = arr[now];
                sz++;
            }
            
            /* cout << "sz -> " << sz << endl; */
            resp += sz / 2;
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
