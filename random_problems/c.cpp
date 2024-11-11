#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    vector<int> arr(32);

    int n = 37;
    for (int i = 0; i <= n; i++) {
        int k = i;
        for (int j = 0; j < 32; j++) {
            if (k & (1 << j)) arr[j]++;
        }
    }


    reverse(arr.begin(), arr.end());
    cout << "digits -> ";
    for (auto c: arr) cout << c << " ";
    cout << endl;
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
