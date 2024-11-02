#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


void solve () {
    int n, k; cin >> n >> k;
    
    map<int, int> brand;

    for (int i = 0; i < k; i++) {
        int b, c; cin >> b >> c;
        brand[b] += c;
    }

    vector<pair<int, int>> arr;
    for (auto [b, c]: brand) {
        arr.push_back({c, b});
    }

    sort(arr.rbegin(), arr.rend());

    int resp = 0;
    if (n >= (int)brand.size()) {
        for (auto [c, b]: arr) resp += c;
    } else {
        for (int i = 0; i < n; i++) {
            resp += arr[i].first;
        }
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
