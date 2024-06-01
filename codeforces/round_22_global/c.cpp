#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    int k = 0;
    int p = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        k += (num&1);
        p += !(num&1);
    }

    if (k % 4 == 2) cout << "Bob" << endl;
    else if (k % 4 == 3) cout << "Alice" << endl;
    else if (k % 4 == 0) cout << "Alice" << endl;
    else if (p % 2 == 1) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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
