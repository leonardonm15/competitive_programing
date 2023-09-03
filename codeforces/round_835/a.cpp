#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int a, b, c; cin >> a >> b >> c;
    set <int> arr;
    arr.insert(a); arr.insert(b); arr.insert(c);
    int i=0;
    for (auto num: arr) {
        if (i == 1) {
            cout <<  num << endl;
        }
        i++;
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
