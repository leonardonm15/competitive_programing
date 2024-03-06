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
/* vector<int> tin(N); */
/* vector<int> tout(N); */
vector<vector<int>> up(N, vector<int>(lg));
vector<vector<int>> st(N, vector<int>(lg));


int lca(int u, int v) {
    if (depth[v] > depth[u]) {
        swap(v, u);
    }
    int d = depth[u] - depth[v];
    for (int i = lg - 1; i >= 0; i--) {
        if (d & (1 << i)) v = up[v][i];
    }

    if (u == v) return u;

    for (int i=lg - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}


int c = 0;
int find(int a) {
    return (daddy[a] == a ? a : daddy[a] = find(daddy[a]));
}

void dfs(int u, int p, int w, int t) {
    up[u][0] = p;
    depth[u] = t;
    vis[u]++;
    for (int j = 1; (1 << j) <= lg; j++) {
        up[u][j] = up[up[p][j - 1]][j - 1];
    }

    for (auto [w, v]: adj[u]) {
        if (!vis[v]) {
            dfs(v, u, w, t + 1);
        }
    }
}

void solve () {
    int n, m, q; cin >> n >> m >> q;
    // teste
    vector<tuple<int, int, int>> edg;
    for (int i=0; i <= n; i++) {
        daddy[i] = i;
        st[i][0] = 0;
        sz[i] = 1;
    }

    for (int i=0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edg.push_back({w, a, b});
    }

    sort(edg.rbegin(), edg.rend());
    cout << "--------" << endl;
    for (auto [w, a, b]: edg) {
        /* cout << w << " "; */
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            /* cout << a << " " << b << " " << w << endl; */
            if (sz[pb] > sz[pa]) swap(pa, pb);
            daddy[pb] = daddy[pa];
            sz[a] += sz[b];
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
    }
    /* cout << endl; */

    cout << "pais -> ";
    for (int i = 1; i <= n; i++) cout << daddy[i] << " ";
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
