#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define pii pair<int, int>
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 2e4 + 5;
const int M = 1e5 + 5; 
const int lg = log2(N) + 1;
vector<pii> adj[N];
vector<int> sz(N);
vector<int> daddy(N);
vector<int> depth(N);
vector<int> vis(N);
const int neutral = 1e9 + 5;
vector<vector<int>> up(N, vector<int>(lg));
vector<vector<int>> st(N, vector<int>(lg, neutral));

pair<int, int> lca(int u, int v) {
    int d = depth[u] - depth[v];
    for (int i = lg - 1; i >= 0; i--) {
        if (d & (1 << i)) v = up[v][i];
    }

    if (u == v) return {0, d};

    int k = 0;
    for (int i=lg - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            k += (1 << i);
            u = up[u][i];
            v = up[v][i];
        }
    }

    k++;
    return {k, d + k};
}

int c = 0;
int find(int a) {
    return (daddy[a] == a ? a : daddy[a] = find(daddy[a]));
}

void dfs(int u, int p, int w, int t) {
    up[u][0] = p;
    depth[u] = t;
    st[u][0] = w;
    vis[u]++;

    // binary lifting + sparse table
    for (int j = 1; j < lg; j++) {
        up[u][j] = up[up[u][j - 1]][j - 1];
        st[u][j] = min(st[u][j - 1], st[up[u][j - 1]][j - 1]);
        cout << "st[u][j] -> " << st[u][j] << endl;
    }

    for (auto [z, v]: adj[u]) {
        if (!vis[v]) {
            dfs(v, u, z, t + 1);
        }
    }
}

void solve () {
    int n, m, q; cin >> n >> m >> q;
    vector<tuple<int, int, int>> edg;
    for (int i=0; i <= n; i++) {
        daddy[i] = i;
        sz[i] = 1;
    }

    for (int i=0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edg.push_back({w, a, b});
    }

    // kruskal
    sort(edg.rbegin(), edg.rend());
    int root = 0;
    for (auto [w, a, b]: edg) {
        root = a;
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            if (sz[pb] > sz[pa]) swap(pa, pb);
            daddy[pb] = daddy[pa];
            sz[pa] += sz[pb];
            adj[a].push_back({w, b});
            adj[b].push_back({w, a});
        }
    }
    
    dfs(root, root, neutral, 0);

    while (q--) {
        int u, v; cin >> u >> v;
        if (depth[u] > depth[v]) swap(u, v);
        auto [d1, d2] = lca(u, v);
        int resp = neutral; 
        /* cout << "resp -> " << resp << endl; */
        /* cout << "st[u][0] -> " << st[u][0] << endl; */
        /* cout << "st[v][0] -> " << st[v][0] << endl; */
        for (int j = lg - 1; j >= 0; j--) {
            if (d1 & (1 << j)) {
                resp = min(resp, st[u][j]);
                u = up[u][j];
            }
        }

        for (int j = lg - 1; j >= 0; j--) {
            if (d2 & (1 << j)) {
                resp = min(resp, st[v][j]);
                v = st[v][j];
            }
        }
        cout << resp << endl;
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
