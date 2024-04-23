#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, p; cin >> n >> p;
    int resp = 0;
    map<int, int> win;
    int k = 1;
    
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (p&1) {
            resp ^= (num&1);
        } else {
            num %= (p + 1);
            if (num == p) resp ^= 2;
            else resp ^= (num&1);
        }
    }

    cout << (resp ? "GOOD" : "BAD") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
