#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int z = 0, o = 0;

    for (auto c: s) {
        if (c == '0') z++;
        else o++;
    }

    int ka = 0;

    for (int i = 0; i < n / 2; i++) {
        if (ka < k) {
            if (z > o && z >= 2) {
                z -= 2;
                ka++;
            } else if (o >= z && o >= 2) {
                o -= 2;
                ka++;
            }
        } else {
            if (o >= 1 && z >= 1) {
                o--;
                z--;
                ka++;
            }
        }
    }

    cout << ((o == 0 && z == 0) ? "YES" : "NO") << endl;
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
