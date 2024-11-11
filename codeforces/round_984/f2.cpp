#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<int> bits(int x) {
    vector<int> arr(64);
    int resp = 0;
    if (!x) return arr;
    int k = __builtin_clzll(x) - 1;
    k = 63 - k - 1;
    arr[0] = ((x + 1) / 2);

    for (int i = 1; i < k; i++) {
        int d = (1 << i);
        int v = (k - i) - 1;
        int am = d * (1ll << v);
        if (x & d) am += (x % (1ll << i)) + 1;
        arr[i] = am;
    }

    arr[k] = (x % (1 << k)) + 1;

    for (int i = 0; i < 63; i++) {
        resp += ((arr[i]&1ll) << i);
    }

    /* reverse(arr.begin(), arr.end()); */

    /* cout << "arr -> "; */
    /* for (auto c: arr) cout << c << " "; */
    /* cout << endl; */

    /* cout << bitset<16>(resp) << endl; */

    return arr;
}

void solve () {
    /* int l; cin >> l; */

    vector<int> arr(64);
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j < 64; j++) {
            if (i & (1ll << j)) arr[j]++;
        }

        /* cout << "_--------------" << endl; */
        vector<int> a = bits(i);

        if (a == arr) cout << "OK" << endl;
        else {
            cout << "NOT OK -> " << i << endl;
            cout << "a -> ";
            for (auto c: a) cout << c << " ";
            cout << endl;

            cout << "arr -> ";
            for (auto c: arr) cout << c << " ";
            cout << endl;
            return;
        }

    }

    /* vector<int> b = bits(r); */
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
