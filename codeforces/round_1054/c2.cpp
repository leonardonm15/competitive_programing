#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n + 5);

    int p = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (arr[num] && num < k) p++;
        if (!arr[num] && num < k) arr[num]++;
        if (num >= k) {
            if (num == k) arr[k]++;
            p++;
        }
    }

    int pv = 0;
    for (int i = 0; i < k; i++) {
        if (!arr[i] && pv < p) {
            pv++; 
            if (arr[k]) arr[k]--;
        }
    }
    
    cout << pv + (arr[k]) << endl;

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
