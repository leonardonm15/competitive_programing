#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; vector<string> s; cin >> n;
    for (int i=0; i < n; i++) {
        string a; cin >> a;
        s.push_back(a);
    }
    int maxi = 0;
    int resp = 0;
    for (int i=0; i < n/2; i++) {
        for (int j=0; j < n/2; j++) {
            int n1 = s[i][j];
            int n2 = s[j][n-1-i];
            int n3 = s[n-1-i][n-1-j];
            int n4 = s[n-1-j][i];
            maxi = max({n1, n2, n3, n4});
            resp += maxi - n1;
            resp += maxi - n2;
            resp += maxi - n3;
            resp += maxi - n4;
        }
    }
    cout << resp << endl;
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
