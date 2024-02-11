#include <bits/stdc++.h>

using namespace std;

//#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxn = 2e5 + 5;

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
        if (v == p) continue;
        if (vis[v]) {
            low[u] = min(low[u], low[v]); // ve quando que eu entrei na backedge
        } else {
            tarjan(v, u);
            low[u] = min(low[v], low[u]);
            if (t[u] < low[v]) {
                bridge[i] = true;
            }
        }
    }
}

bool flag = false;
vector<int> stc;
void dfs(int u, int v, int k) {
    /* cout << "u -> " << u << endl; */
    stc.push_back(u);
    vis[u]++;
    if (u == k) {
        for (auto cara: stc) resp.push_back(cara);
        return;
    }
    for (auto [w, c, i]: adj[u]) {
        if (c != v && !vis[c]) {
            dfs(c, u, k);
        }
    }
    stc.pop_back();
}

int tc = 0;
void solve () {
    int n, m; cin >> n >> m;
    tc++;
    // recebe os caras
    for (int i=1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v, i});
        adj[v].push_back({w, u, i});
        edg.push_back({w, u, v, i});
    }

    /* if (tc == 22) { */
    /*     cout << n << "#" << m << "#"; */
    /*     for (auto [w, u, v, i]: edg) { */
    /*         cout << u << "-" << v << "-" << w << "#"; */
    /*     } */
    /* } */

    // faz dfs, acha os ciclos e marca no is_bridge
    for (int i=1; i <= n; i++) {
        if (!vis[i]) tarjan(i, -1);
    }

    sort(edg.begin(), edg.end());

    /* cout << "edg -> "; */
    /* for (auto [w, u, v, i]: edg) { */
    /*     cout << w << " "; */
    /* } */
    /* cout << endl; */

    /* cout << "bridge -> "; */
    /* for (int i=0; i <= m; i++) cout << bridge[i] << " "; */
    /* cout << endl; */

    for (int i=1; i <= n; i++) vis[i] = 0;

    for (auto [w, u, v, i]: edg) {
        /* cout << "u -> " << u << endl; */
        /* cout << "v -> " << v << endl; */
        /* cout << "w -> " << w << endl; */
        /* cout << "-----------" << endl; */
        if (!bridge[i]) {
            /* resp.push_back(v); */
            dfs(u, v, v);
            cout << w << " " << resp.size() << endl;
            for (auto cara: resp) cout << cara << " ";
            cout << endl;
            break;
        }
    }

    resp.clear();
    edg.clear();
    stc.clear();
    for (int i=0; i <= m; i++) {
        vis[i] = 0;
        bridge[i] = false;
        adj[i].clear();
        low[i] = -1;
        flag = false;
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
