#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxa = 1e9;
void solve () {
    int n; cin >> n;
    int mn1 = 1e9;
    int min2 = 1e9;
    int resp1 = 0;
    int resp2 = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        resp1 += num;
        mn1 = min(mn, num);
    }
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        resp2 += num;
        mn2 = min(mn, num);
    }
    if (
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
