#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '1') q[j]++;
        }
    }

    cout << "q -> ";
    for (auto c: q) cout << c << " ";
    cout << endl;


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
