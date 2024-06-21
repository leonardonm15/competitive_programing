#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int tc = 0;
void solve () {
    tc++;
    int x, y; cin >> x >> y;
    if (tc == 108) {
        cout << x << "#" << y << endl;
    }
    if (y > x) swap(x, y);
    
    if (y == 0) {
        for (int i = 0; i <= 33; i++) {
            if (x & (1 << i)) {
                cout << (1 << i) << endl;
                return;
            }
        }
    }

    for (int i = 0; i <= 33; i++) {
        int k = (1 << i);
        int a = (x & k);
        int b = (y & k);
        /* cout << "a -> " << a << endl; */
        /* cout << "b -> " << b << endl; */
        /* cout << "i -> " << i << endl; */

        if (a != b) {
            cout << k << endl;
            return;
        }

        if (k > x || k > y) {
            cout << k * 2 << endl;
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
