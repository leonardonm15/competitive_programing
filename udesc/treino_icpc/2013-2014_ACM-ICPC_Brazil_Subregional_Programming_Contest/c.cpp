#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxm = (60 * 1e3) + 5;
vector<int> adj[maxm];
vector<int> idade(505);
vector<int> resp(505, 1e9 + 5);

void dfs(int u) {
    for (auto v: adj[u]) {
        if (resp[v] < resp[u]) {
            resp[u] = resp[v];
            return;
        }
    }
}

void solve () {
    int n, m, q; cin >> n >> m >> q;

    for (int i=0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i=0; i < m; i++) {
        adj[i].clear();
        idade[min(504, i)] = 0;
        resp[min(504, i)] = 0;
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
