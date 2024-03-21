#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;
vector<int> adj[N], rev[N];
vector<int> vis(N);
vector<int> comp(N);

void dfs2(int u, vector<int> &sccs, int it) {
    vis[u]++;
    for (auto cara: rev[u]) {
        if (!vis[cara]) dfs2(cara, sccs, it);
    }
    sccs.push_back(u);
    comp[u] = it;
}

void dfs1(int u, vector<int>& stc) {
    vis[u]++;
    stc.push_back(u);
    for (auto cara: adj[u]) {
        if (!vis[cara]) dfs1(cara);
    }
}

void solve () {
    int n; cin >> n;
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        adj[i].push_back(num);
        rev[num].push_back(i);
    }

    vector<int> stc;
    dfs(1);
    vis.assign(n + 1, 0);

    vector<vector<int>>
    int it = 1;
    while ((int) stc.size()){
        int cara = stc.top();
        stc.pop_back();
        vector<int> sccs;
        if (!vis[cara]) dfs2(cara, sccs, it);
        it++;
    }

    separar os pontos finais scc
    juntar os pontos finais
    e fazer os cilcos

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
