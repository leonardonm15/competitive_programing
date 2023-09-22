#include <bits/stdc++.h>

using namespace std;
# define int long long

void solve () {
    int n; cin >> n;
    vector<int> q;
    int maxn = 1e7;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (num < maxn) maxn = num;
        q.push_back(num);
    }
    int resp = 1;
    bool flag = true;
    for (int i=0; i < n; i++) {
        if (q[i] == maxn && flag){
            q[i]++;
            flag = false;
        }
        resp *= q[i];
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
