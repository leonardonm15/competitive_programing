#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
vector<bool> vis(maxn);
vector<int> dis(maxn, maxn);
int maxp = 0;
int maxd = 0;

void dfs(int n, int p = 0) {
    vis[n] = true;
    if (p > maxp) {
        maxp = p;
        maxd = n;
    }
    for (auto cara: adj[n]) {
        if (vis[cara]) continue;
        dfs(cara, p+1);
    }
}

void bfs(int n) {
    queue<int> q;
    q.push(n);
    dis[n] = 0; // distancia pra minha root é 0 sempre;
    while(!q.empty()) {
        int i = q.front();
    }
}

void solve () {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    bfs(maxd);
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
