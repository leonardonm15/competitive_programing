#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    int begin = n - k + 1;
    int end = n;
    int even = (end - begin + 2 - (begin % 2)) / 2;
    int odd = (begin - end + 1) - even;
    
    if (odd&1) cout << "NO" << endl;
    else cout << "YES" << endl;
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
