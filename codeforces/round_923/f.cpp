#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxn = 1e5 + 5;

vector<vector<tuple<int, int, int>>> adj(maxn); // w v i
vector<tuple<int, int, int, int>> edg;
vector<int> vis(maxn);
vector<bool> bridge(maxn);
vector<int> low(maxn, -1);
vector<int> t(maxn);
vector<int> resp;

int timer = 0;
void tarjan(int u, int p) {
    timer++;
    vis[u]++;
    low[u] = timer;
    t[u] = timer;
    for (auto [w, v, i]: adj[u]) {
        if (v == u) continue;
        if (vis[v]) {
            low[u] = min(low[u], t[v]); // ve quando que eu entrei na backedge
        } else {
            tarjan(v, u);
            low[u] = min(low[v], low[u]);
            if (t[u] < low[v]) {
                bridge[i] = true;
            }
        }
    }
}

void dfs(int u, int v, int k) {
    vis[u]++;
    resp.push_back(u);
    if (u == k) return;
    for (auto [w, c, i]: adj[u]) {
        if (c != v && !bridge[i] && !vis[c]) {
            dfs(c, u, k);
        }
    }
}

void solve () {
    int n, m; cin >> n >> m;
    // recebe os caras
    for (int i=1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v, i});
        adj[v].push_back({w, u, i});
        edg.push_back({w, u, v, i});
    }

    // faz dfs, acha os ciclos e marca no is_bridge
    for (int i=1; i <= n; i++) {
        if (!vis[i]) tarjan(i, -1);
    }

    sort(edg.begin(), edg.end());

    for (int i=1; i <= n; i++) vis[i] = 0;

    for (auto [w, u, v, i]: edg) {
        /* cout << "w -> " << w << endl; */
        if (!bridge[i]) {
            dfs(u, v, v);
            cout << w << " " << resp.size() << endl;
            for (auto cara: resp) cout << cara << " ";
            cout << endl;
            break;
        }
    }

    resp.clear();
    edg.clear();
    for (int i=0; i <= m; i++) {
        vis[i] = 0;
        bridge[i] = false;
        adj[i].clear();
        low[i] = -1;
        t[i] = 0;
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
