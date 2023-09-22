#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, h; cin >> n >> h;
    vector<int> arr;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int q0 = 1; // square multiplier
    int qq = 1; // curent squares
    int nw = arr[0];
    int resp = arr[0];
    arr[0] = 0;
    for (int i=0; i < n; i++) {
        int a = arr[i];
        int qr = 1;
        for (int j=i + 1; j < n; j++) {
            if (arr[j] == a) qr++;
            else break;
        }
        int diff = a - resp;
    }
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
