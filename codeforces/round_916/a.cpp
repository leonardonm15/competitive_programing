#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    /* cout << "n -> " << n << endl; */
    string s; cin >> s;
    vector<int> arr(27);
    for (int i=1; i <= 26; i++) {
        arr[i] = i;
    }
    int resp = 0;
    for (auto c: s) {
        int k = c - 'A' + 1;
        arr[k]--;
    }
    for (int i=1; i <= 26; i++) {
        /* cout << "arr[i] -> " << arr[i] << endl; */
        if (arr[i] <= 0) resp++;
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
