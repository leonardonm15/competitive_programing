#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    int k = 1;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        k *= num;
    }
    n <<= 1;
    int k2 = k | n;
    cout << "k2 -> " << k2 << endl;
    int resp = __builtin_popcount(k2) - __builtin_popcount(k);
    cout << (resp ? resp : -1) << endl;
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
