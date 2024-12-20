#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    int x = 0;
    string resp = "Kosuke";
    int i = 1;
    while (abs(x) < n) {
        /* cout << "x -> " << x << endl; */
        if (i&1) {
            x -= (2 * i) - 1;
            resp = "Kosuke";
        } else {
            x += (2 * i) - 1;
            resp = "Sakurako";
        }

        i++;
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
