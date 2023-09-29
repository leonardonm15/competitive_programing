#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int, int>
const int maxn = 500 + 5;
const int inf = 1e17;
vector<vector<pii>> adj(n);

void dks (int n) {
    priority_queue<pii, vector<pii>, greater<pii>>;
    vector<int> d(maxn, inf);
    
}

void solve () {
    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i <  m ; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

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
