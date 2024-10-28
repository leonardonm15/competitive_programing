#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int x, y, k; cin >> x >> y >> k;

    int msq = min(x, y);

    pair<int, int> a, b, c, d;

    a.first = 0;
    a.second = 0;

    b.first = msq;
    b.second = msq;

    c.first = 0; 
    c.second = msq;
    
    d.first = msq;
    d.second = 0;


    cout << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
    cout << c.first << " " << c.second << " " << d.first << " " << d.second << endl;
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
