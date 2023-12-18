#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    map<int, int> map;

    for (int i=0; i < n; i++) {
        int k = 1;
        int num; cin >> num;
        int resp = 1;
        while (num > 0) {
            /* cout << "num -> " << num << endl; */
            if (num&1) resp = k;
            num >>= 1;
            k++;
        }
        map[resp]++;
    }
    int resp = 0;
    for (auto [cara, f]: map) {
        /* cout << "cara -> " << cara << endl; */
        /* cout << "f -> " << f << endl; */
        if (f >= 2) resp += (f * (f-1))/2;
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
