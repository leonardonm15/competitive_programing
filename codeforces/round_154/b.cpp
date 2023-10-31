#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

void solve () {
    string sa, sb; cin >> sa >> sb;
    int n = sa.size();
    if (sa == sb) {
        puts("YES");
        return;
    }
    if (n == 3) {
        puts("NO");
        return;
    }
    for(int i=0; i < n - 1; i++) {
        if ((sa[i] == sa[0] && sa[i+1] == sa[n-1]) &&
            (sb[i] == sb[0] && sb[i+1] == sb[n-1])) {
            puts("YES");
            return;
        }
    }
    puts("NO");
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

