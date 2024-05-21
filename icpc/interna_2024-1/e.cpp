#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, q; cin >> n >> q;
    vector<int> gcds;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    gcds.push_back(arr[0]);
    for (int i=1; i < n; i++) gcds.push_back(gcd(arr[i], gcds[i - 1]));

    int r = gcds.size() - 1;
    while (q--) {
        int t, num; cin >> t >> num;

        /* cout << "--------------" << endl; */
        /* cout << "gcds -> "; */
        /* for (auto c: gcds) cout << c << " "; */
        /* cout << endl; */

        if (t == 1) {
            gcds.push_back(gcd(gcds[gcds.size() - 1], num));
            r++;
        } else if (t == 2) {
            r -= num;
            while (num--) gcds.pop_back();
        } else {
            /* cout << "r -> " << r << endl; */
            /* cout << "gcd[r] -> " << gcds[r] << endl; */
            if (gcds[r] % num == 0) cout << "SIM" << endl;
            else cout << "NAO" << endl;
        }
    }
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
