#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;
vector<int> adj[N], rev[N];
vector<set<int>> dag(N);
vector<int> vis(N);
vector<int> comp(N); // componente
vector<pair<int, set<int>> rep(N); // representante
vector<int> track(N, -1);
vector<set<pair<int, int>>> resp(N);

int montar_dag(int u, int p) {
    // monta a dag com os representantes de cada SCC 
    // + monta a DAG
    vis[u]++;

    (auto cara: adj[u]) {
    }
}

void dfs2(int u, vector<int> &sccs, int it) {
    // acha os componentes conexos e os representantes deles
    vis[u]++;
    for (auto cara: rev[u]) {
        if (!vis[cara]) dfs2(cara, sccs, it);
    }
    sccs.push_back(u);
    comp[u] = it;
}

void dfs1(int u, vector<int>& stc) {
    // acha a ordem de execução da dfs
    vis[u]++;
    for (auto cara: adj[u]) {
        if (!vis[cara]) dfs1(cara, stc);
    }

    stc.push_back(u);
}

void solve () {
    int n; cin >> n;
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        adj[i].push_back(num);
        rev[num].push_back(i);
    }

    vector<int> stc;
    for (int i=0; i <= n; i++) {
        if (!vis[i]) dfs1(i, stc);
    }
    vis.assign(n + 1, 0);

    int it = 1;
    vector<int> stc2 = stc;
    while ((int) stc.size()){
        int cara = stc.back();
        stc.pop_back();
        rep[it] = cara; // representante do componente conexo
        vector<int> sccs;
        if (!vis[cara]) dfs2(cara, sccs, it);
        it++;
    }

    vis.assign(n + 1, 0);
    while (stc2.size() > 0) {
        // fazer o caminho do grafo normal a partir da folha montando o track
        int u = stc2.back();
        dfs3(u);
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
