#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;
const int M = 3e5 + 5;
const int mod = 1e9 + 7;
vector<int> adj[N];
vector<int> rev[N];
vector<int> price(N, 0);
vector<int> vis(N);
set<int> sccs[N];

void dfs(int u, vector<int>& stc) {
    vis[u]++;
    for (auto cara: adj[u]) {
        if (!vis[cara]) dfs(cara, stc);
    }

    stc.push_back(u);
}

void dfsr(int u, int cc) {
    if (!vis[u]) sccs[cc].emplace(u);
    vis[u]++;
    for (auto cara: rev[u]) {
        if (!vis[cara]) dfsr(cara, cc);
    }
}


void solve () {
    int n; cin >> n;
    for (int i=1; i <= n; i++) cin >> price[i];
    int m; cin >> m;
    for (int i=0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<int> stc;
    for (int i=1; i <= n; i++) {
        if (!vis[i]) dfs(i, stc);
    }

    int cc = 0;
    vis.assign(n + 1, 0);
    while ((int)stc.size()) {
        int u = stc.back();
        stc.pop_back();
        dfsr(u, cc);
        cc++;
    }

    int r1 = 0;
    int r2 = 1;

    for (int i=0; i <= cc; i++) {
        int mini = (int)(1e18) + 5;
        int qnt = 1;
        for (auto cara: sccs[i]) {
            if (price[cara] == mini) qnt++;
            else if (price[cara] < mini) {
                mini = price[cara];
                qnt = 1;
            }
        }

        if (sccs[i].size()) {
            r1 += mini;
            r2 *= qnt;
            r2 %= mod;
        }
    }

    cout << r1 << " " << r2 << endl;
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
