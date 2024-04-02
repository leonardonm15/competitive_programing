#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 2e5 + 5;
vector<int> g[N];
vector<int> tg[N];
vector<int> rep(N);
vector<int> status(N);
vector<int> swt[N];
vector<int> vis(N);

void implie(int u, int v, bool us, bool vs) {
    // se chover a rua ta molhada
    g[2 * u + us].push_back(2 * v + vs);
    // se nao ta molhado é pq nao choveu
    g[2 * v + !vs].push_back(2 * u + !us);

    tg[2 * v + vs].push_back(2 * u + us);
    tg[2 * u + !us].push_back(2 * v + !vs);
}

void add_xor(int u, int v) {
    implie(u, v, 0, 1);
    implie(u, v, 1, 0);
}

void add_eq(int u, int v) {
    // se eu usar o a eu uso o b tbm
    implie(u, v, 0, 0);
    // se eu nao usar o a eu nao uso o b tbm
    implie(u, v, 1, 1);
}

void dfs(int u, vector<int>& stc) {
    vis[u]++;
    for (auto v: g[u]) if (!vis[v]) {
        dfs(v, stc);
    }
    stc.push_back(u);
}

void dfsr(int u, int cls) {
    vis[u]++;
    rep[u] = cls;
    for (auto v: tg[u]) if (!vis[v]) {
        dfsr(v, cls);
    }
}

void solve () {
    int n, m; cin >> n >> m;
    for (int i=1; i <= n; i++) cin >> status[i];

    for (int i=1; i <= m; i++) {
        int k; cin >> k;
        while (k--) {
            int cara; cin >> cara;
            swt[cara].push_back(i);
        }
    }

    for (int i=1; i <= n; i++) {
        if (status[i]) add_eq(swt[i][0], swt[i][1]);
        else add_xor(swt[i][0], swt[i][1]);
    }

    vector<int> stc;
    for (int i=1; i <= 2 * m + 1; i++) {
        if (!vis[i]) dfs(i, stc);
    }

    int cl = 1;
    vis.assign(2 * m + 1, 0);
    while ((int)stc.size()) {
        int u = stc.back();
        stc.pop_back();
        if (!vis[u]) dfsr(u, cl++);
    }

    bool flag = true;
    for (int i=1; i <= m; i++) {
        if (rep[2 * i] == rep[2 * i + 1] && rep[2 * i] && rep[2 * i + 1]) flag = false;
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    for (int i=0; i <= 2 * max(n, m) + 2; i++) {
        rep[i] = 0;
        g[i].clear();
        tg[i].clear();
        status[i] = 0;
        swt[i].clear();
        vis[i] = 0;
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
