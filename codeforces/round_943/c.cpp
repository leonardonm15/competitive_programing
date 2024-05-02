#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n - 1);
    for (int i=0; i < n - 1; i++) cin >> arr[i];

    vector<int> resp;
    resp.push_back(arr[0] + 501);
    for (int i=0; i < n - 1; i++) {
        resp.push_back(resp[i] + arr[i]);
    }
    
    for (auto cara: resp) cout << cara << " ";
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

