#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int resp = 0;
    vector<int> arr;
    bool flag = true;
    for (int i=0; i < n; i++) {
        if (s[i] == 'B') {
            flag = false;
            if (arr.size() > 0 && ((i - arr[0])+1) > k) {
                resp++;
                arr.clear();
                arr.push_back(i);
                continue;
            }
            arr.push_back(i);
        }
    }
    if (arr.size() > 0) resp++;
    if (flag) cout << 0 << endl;
    else cout << resp << endl;
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
