#include <bits/stdc++.h>
 
using namespace std;
//#define int long long
 
void solve () {
    int n; cin >> n;
    vector<int> arr(n - 1);
    vector<int> resp;
    for (int i=0; i < n - 1; i++) cin >> arr[i];
    // arr[i] = max(xi e xi + 1)
    
    resp.push_back(arr[0]);
    for (int i=1; i < n - 1; i++) {
        resp.push_back(min(arr[i], arr[i - 1]));
    }

    resp.push_back(arr[arr.size() - 1]);
    for (auto c: resp) {
        cout << c << " ";
    }
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
