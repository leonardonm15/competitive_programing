#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int a, b; cin >> a >> b;
    
    b %= 2;
    if ((b == 1 && !(a&1) && a > 0) || (!(a&1) && !(b&1))) cout << "YES" << endl;
    else cout << "NO" << endl;
    
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