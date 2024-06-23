#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int tc = 0;
void solve () {
    tc++;
    int x, y; cin >> x >> y;

    for (int i = 0; i <= 33; i++) {
        int k = (1 << i);
        int a = (x & k);
        int b = (y & k);
        if (a != b) {
            cout << k << endl;
            return;
        }
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
