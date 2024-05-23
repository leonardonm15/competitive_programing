#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;
vector<int> adj[N];
set<int> color[N];
int resp[N], c[N], vis[N];


void dfs(int u) {
    vis[u]++;
    set<int> ms;
    ms.emplace(c[u]);

    for (auto v: adj[u]) if (!vis[v]) dfs(v);

    for (auto v: adj[u]) {
        if (color[v].size() > ms.size()) swap(color[v], ms);
    }

    for (auto v: adj[u]) {
        for (auto cara: color[v]) {
            ms.emplace(cara);
        }
    }

    resp[u] = ms.size();
    swap(color[u], ms);
}

void solve () {
    int n; cin >> n;
    for (int i=1; i <= n; i++) cin >> c[i];

    for (int i=0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i=1; i <= n; i++) cout << resp[i] << " ";
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
