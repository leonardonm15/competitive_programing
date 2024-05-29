#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> jda[N];
int vis[N];
int color[N];
vector<int> ts;

void dfs(int u) {
    vis[u]++;
    for (auto v: adj[u]) if (!vis[v]) dfs(v);
    ts.push_back(u);
}

void dfsr(int u, int c) {
    vis[u]++;
    color[u] = c;
    for (auto v: jda[u]) if (!vis[v]) dfsr(v, c);
}

void solve () {
    int n, m; cin >> n >> m;
    for (int i=0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }

    for (int i=1; i <= n; i++) if (!vis[i]) dfs(i);
    for (int i=1; i <= n; i++) vis[i] = 0;
    reverse(ts.begin(), ts.end());

    int k = 1;
    while (ts.size()) {
        int u = ts.back();
        ts.pop_back();
        if (!vis[u]) dfsr(u, k++);
    }

    cout << k - 1 << endl;
    for (int i=1; i <= n; i++) cout << color[i] << " " ;
    cout << endl;
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
