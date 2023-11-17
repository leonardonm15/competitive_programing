#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, m; cin >> n >> m;
    int l = 0;
    int maxi = 0;
    int o = 10;
    if (m <= 5) {
        cout << n * m << endl;
        return;
    }
    if (m <= 10) o = 5;
    for (int i=0; i <= o; i++) {
        int k = m - i;
        int p = n * k;
        int v = 0;
        if (i == 0) {
            string q = to_string(m);
            p = n * ((long long) pow(10, q.size() -1));
            /* cout << "p -> " << p << endl; */
        }
        while (p % 10 == 0) {
            v++;
            p /= 10;
        }
        if (v > l) {
            maxi = n * k;
            l = v;
        }
    }
    
    cout << maxi << endl;

    /* int p = 0; */
    /* string s; cin >> s; */
    /* int k = s[0] - '0'; */
    /* if (k > 5) k = 5; */
    /* if (s.size() > 1) p = s.size() - 1; */
    /* p = pow(10, p); */
    /* cout << n * k * p << endl; */
    /* for (int i=0; i < n; */ 
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
