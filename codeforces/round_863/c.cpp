#include <bits/stdc++.h>
 
using namespace std;
//#define int long long
 
void solve () {
    int n; cin >> n;
    vector<int> arr(n - 1);
    vector<int> resp;
    for (int i=0; i < n - 1; i++) cin >> arr[i];
    arr.push_back(-1);

    // arr[i] = max(xi e xi + 1)
    
    resp.push_back(arr[0]);
    for (int i=0; i < n; i++) {
        int lc = resp[resp.size() - 1];
        int x = lc;
        if (lc == -1) break;
        if (arr[i] == max(lc, x)) {
            resp.push_back(arr[i]);
        } else {
           resp.push_back(arr[i]);
           resp.push_back(arr[i]);
        }
    }

    resp.pop_back();
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
