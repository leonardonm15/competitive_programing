#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
int up[20][N];
int st[20][N];
vector<int> pais(N);
vector<int> deph(N);

int lca(int a, int b) {
    if (deph[a] > deph[b]) swap(a, b);
    int diff = deph[b] - deph[a];
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
    deph[u] = d;
    for (auto v: adj[u]) if (v != p) {
        dfs(v, u, d + 1);
    }
}

int intersect(int a, int dlab, int u, int dluv) {
    /* cout << "a -> " << a << endl; */
    /* cout << "dlab -> " << dlab << endl; */
    /* cout << "u -> " << u << endl; */
    /* cout << "dlub -> " << dluv << endl; */
    int lau = lca(a, u);
    return max(0ll, deph[lau] - max(dlab, dluv) + 1);
}

int query(int a, int b, int u, int v) {
    int lab = lca(a, b);
    int luv = lca(u, v);
    int x, y, z, w;

    // inter a - dlab com u - dluv
    w = intersect(a, deph[lab], u, deph[luv]);

    // int a - dlab com v - dluv
    x = intersect(a, deph[lab], v, deph[luv] + 1);

    // int b - dlab com u - dluv
    y = intersect(b, deph[lab] + 1, u, deph[luv]);

    // int b - dlab com v - dluv
    z = intersect(b, deph[lab] + 1, v, deph[luv] + 1);

    return x + y + z + w;
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
    for (int i=0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, 1);
    calc(n);

    while (q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << query(a, b, c, d) << endl;
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
