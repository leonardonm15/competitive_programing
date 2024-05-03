#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 2 << endl;
    
    for (int i=n; i >= 3; i--) cout << i << " " << i << endl;
    
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
