#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
vector<bool> vis(maxn);
vector<int> out;

void dfs(int n) {
    vis[n] = true;
    for (auto vert: adj[n]) { 
        if (vis[vert] == true) continue;
        dfs(vert);
    }
}

void solve () {
    int n, m; cin >> n >> m;
    for (int i=0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i <= n; i++) {
        if (vis[i] == false) {
            dfs(i);
            out.push_back(i);
        }
    }
    int sz = out.size();
    cout << sz - 1 << endl;
    for (int i=1; i < sz; i++) {
        cout << out[0] << " " << out[i] << endl;
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
