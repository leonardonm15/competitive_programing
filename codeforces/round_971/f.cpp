#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, q; cin >> n >> q;
    vector<int> arr(n);

    int sum = 0;
    vector<int> pref;

    pref.push_back(sum);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        sum += num;
        pref.push_back(num);
        arr[i] = num;
    }


    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int shift = (l + 1) / n;
        int inicio = (l + 1) % n;


        // 1 2 3 4 5
        // 2 3 4 5 1
        // 3 4 5 1 2
        // 4 5 1 2 3
        // 5 1 2 3 4
        // 1 2 3 4 5
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
