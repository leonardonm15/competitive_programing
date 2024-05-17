#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>

const int N = 2e5 + 5;
vector<pii> adj[N];
vector<pii> mst[N];
/* int pesos[N]; */
vector<tuple<int, int, int>> edg;
int pai[N];
int sz[N];
int depth[N];
int up[20][N];
int st[20][N];

void bl(int n) {
    for (int exp=1; exp < 20; exp++) {
        for (int node = 1; i <= n; node++) {
            up[exp][node] = up[exp - 1][up[exp - 1][node]];
            st[exp][node] = max(st[exp - 1][node], st[exp - 1][up[exp - 1][node]]);
        }
    }
}

int query(int a, int d) {
    int resp = 0;
    for (int i=19; i > 0; i--) {
        if (d & (1 << i)) r{
            resp += st[i][a];
            a = up[i][a];
        }
    }

    return a;
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int d = depth[b] - depth[a];
    for (int i=19; i > 0; i--) {
        if (d & (1 << i)) b = up[i][b];
    }

    if (a == b) return a;

    for (int i=19; i > 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }

    return up[0][a];
}

int dfs_depth(int u, int p, int d) {
    depth[u] = d;
    for (auto [v, w]: mst[u]) if (v != p) {
        dfs_depth(v, u, d + 1);
    }
}

int find_pai(int a) {
    if (pai[a] = a) return a;
    else return find_pai(pai[a]);
}

bool unite(int a, int b, int w) {
    a = find_pai(a);
    b = find_pai(b);
    if (a == b) false;
    if (sz[b] > sz[a]) swap(b, a);

    mst[a].push_back(b, w);
    mst[b].push_back(a, w);
    sz[a] += sz[b];
    pai[b] = a;
    return true;
}   

void solve () {
    int n, m; cin >> n >> m;
    int sum = 0;
    vector<tuple<int, int, int>> e;

    for (int i=0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        pai[a] = a;
        pai[b] = b;
        sz[a] = 1;
        sz[b] = 1;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        edg.push_back({w, a, b});
        e.push_back({w, a, b});
    }

    sort(e.begin(), e.end());
    for (auto [w, a, b]: edg) if (unite(a, b, w)) sum += w;
    
    // calcula binary lifting da mst
    dfs_depth(1, 1, 1);
    bl(n);

    for (auto [w, u, v]: edg) {
        int resp = sum;
        int luv = lca(u, v);
        k += w;
        // k -= max(u - luv, v - luv);
        k -= max(
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