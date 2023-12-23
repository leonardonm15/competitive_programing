#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> resp;
    for (int i=n; i >= 1; i--) {
        resp.push_back(i);
    }
    
    reverse(resp.begin(), resp.begin() + (k + 1));

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
