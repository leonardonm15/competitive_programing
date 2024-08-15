#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.rbegin(), arr.rend());

    int a = 0;
    int b = 0;
    int posso = 0;

    vector<int> bs;
    for (int i = 0; i < n; i++) {
        if (i&1) b += arr[i];
        else a += arr[i];
    }

    for (int i = 1; i < n; i += 2) {
        posso += arr[i - 1] - arr[i];
    }

    /* cout << "a -> " << a << endl; */
    /* cout << "b -> " << b << endl; */
    /* cout << "a - b -> " << a - b << endl; */

    int v = min({posso, k, a - b});
    cout << (a - (b + v)) << endl;

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
