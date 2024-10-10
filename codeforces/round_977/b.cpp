#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> freq(n + 5);
    map<int, int> mp; // k é mt grande

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] <= n + 2) freq[arr[i]]++;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i <= n; i++) {
        if (freq[i]) {
            mp[i % k] += freq[i];
        }

        if (!mp[i % k]) {
            cout << i << endl;
            return;
        } else {
            mp[i % k]--;
        }
    }
}
/* cout << "Opa -> " << */

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
