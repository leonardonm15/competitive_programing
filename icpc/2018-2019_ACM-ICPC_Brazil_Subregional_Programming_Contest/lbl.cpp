#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> up[20][N];
vector<int> st[20][N];
vector<int> pais(N);
vector<int> deph(N);

int lca(int a, int b) {
    if (deph[a] > depth[b]) swap(a, b);
    int diff = a - b;
    for (int i=19; i >= 0; i--) {
        if (diff&(1 << i)) b = up[i][b];
    }

    if (a == b) return a;

    for (int i=19; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }

    return up[0][a];
}

void dfs(int u, int p, int d) {
    pais[u] = p;
    depth[u] = d;
    for (auto v: adj[u]) if (v  != p) {
        dfs(v, u, d + 1);
    }
}

int intersect(int a, int b, int u, int v) {
    int lab = lca(a, b);
    int luv = lca(u, v);

    if (deph[lab] > deph[luv]) swap(lab, luv);

    /* int dav = deph[lab] - deph[luv]; */
    /* for (int i=19; i >= 0; i--) { */
    /*     if (dav&(1 << i)) luv = up[i][luv]; */
    /* } */

}

void calc(int n) {
    for (int i=1; i <= n; i++) up[0][i] = pais[i];
    for (int exp=1; exp < 20; exp++) {
        for (int node=1; node <= n; node++) {
            up[exp][node] = up[exp - 1][up[exp - 1][node]];
        }
    }
}

void solve () {
    int n, q; cin >> n >> q;
    dfs(1, 1);
    calc(n);
    for (int i=0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
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
