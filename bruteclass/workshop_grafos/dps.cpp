#include <bits/stdc++.h>

using namespace std;
//#define int long long

const int maxn = 1e5 + 5;
bool vis[maxn];
vector<int> adj[maxn];

void dfs(int n) {
    vis[n] = true;
    for (auto ver: adj[n]) {
        if (vis[ver]) continue;
        dfs(ver);
    }
}

void solve () {
    int n, m; cin >> n >> m;
    for (int i=0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int busca; cin >> busca;
    dfs(busca);
    cout << (vis[1] ? "YES" : "NO") << endl;
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
