#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
vector<int> vis(N);
vector<int> max_sub(N);

int dfs(int u, int p) {
    vis[u]++;
    int resp = 0;
    for (auto &[cara, peso]: adj[u]) {
        if (!vis[cara]) {
            max_sub[u] = max(max_sub[u], dfs(cara, u) + peso);
        }
    }
    
    if (adj[u].size() == 1 && adj[u][0].first != p) {
        max_sub[u] = adj[u][0].second;
        return max_sub[u];
    }
    else {
        max_sub[u] += resp;
        return max_sub[u];
    }
}

void solve() {
    int n; cin >> n;
    for (int i=0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int c = dfs(1, -1);

    int resp = 0;
    for (auto [cara, peso]: adj[1]) {
        resp = max(resp, max_sub[cara] + peso);
    }

    cout << resp << endl;

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
