#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    map<int, int> map;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        for (int i=2; i * i <= num; i++) {
            while (num % i == 0) {
                map[i]++;
                num /= i;
            }
        }
        if (num != 1) map[num]++;
    }
    for (auto [p, f]: map) {
        /* cout << "p -> " <<  p << endl; */
        /* cout << "f -> " << f << endl; */
        if (f % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
