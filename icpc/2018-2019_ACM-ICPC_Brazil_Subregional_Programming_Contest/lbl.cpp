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

int intersect(int a, int lab, int u, int luv) {
    int lau = lca(a, u);
    if (deph[lau] < deph[lab]) return 0;
    int d = deph[lau] - deph[lab];
    return d;
}

int query(int a, int b, int u, int v) {
    int lab = lca(a, b);
    int luv = lca(u, v);
    /* cout << "lab -> " << lab << endl; */
    /* cout << "luv -> " << luv << endl; */
    int x, y, z, w;

    // inter a - lab com u - luv
    w = intersect(a, lab, u, luv);

    // int a - lab com v - luv
    x = intersect(a, lab, v, luv);
    if (w > 0 && x > 0) x--;

    // int b - lab com u - luv
    y = intersect(b, lab, u, luv);

    // int b - lab com v - luv
    z = intersect(b, lab, v, luv);
    if (y > 0 && z > 0) z--;
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
