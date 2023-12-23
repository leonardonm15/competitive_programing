#include <bits/stdc++.h>

using namespace std;
//#define int long long

const int maxn = 2e5 + 5;

void solve () {
    int n; cin >> n;
    vector<int> adj[maxn];
    vector<int> v(n - 1);

    for (int i=0; i < n - 1; i++) cin >> v[i];
    for (int i=0; i < n - 1; i++) {
        
    }

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
