#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, q; cin >> n >> q;
    int soma = 0;
    vector<int> p(n);
    vector<int> arr(n);

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        p[i] = num;
    }

    sort(p.rbegin(), p.rend());

    for (int i=0; i < n; i++) {
        soma += p[i];
        arr[i] = soma;
    }

    /* cout << endl; */
    /* cout << "caras - > "; */
    /* for (auto cara: arr) cout << cara << " "; */
    /* cout << endl; */

    while (q--) {
        int num; cin >> num;
        int k = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
        /* cout << "k -> " << k << endl; */
        if (k >= n || arr[k] < num) cout << -1 << endl;
        else cout << k + 1 << endl;
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
