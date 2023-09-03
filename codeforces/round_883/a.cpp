#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    int c = 0;
    for (int i=0; i < n; i++) {
        int num1, num2; cin >> num1 >> num2;
        if (num1 > num2) c++;
    }
    cout << c << endl;
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
