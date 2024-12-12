#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (int i = 1; i <= n; i++) arr[i - 1] = i;

    do {
        int minimo = arr[0];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

            }
        }
    } while (next_permutation(arr.begin(), arr.end()));

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
