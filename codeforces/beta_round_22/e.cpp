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
vector<int> rep(N); // representante
vector<pair<int, int>> lft(N); // quantidade de caras que tao saindo de alguem
vector<pair<int, int>> arrive(N); // quantidade de caras que tao entrando em alguem

void montar_dag(int u) {
    // monta a dag com os representantes de cada SCC 
    // + monta a DAG
    vis[u]++;
    for (auto cara: adj[u]) {
        if (rep[u] != rep[cara]) {
            dag[rep[u]].emplace(rep[cara]);
            lft[rep[u]].first++;
            arrive[rep[cara]].first++;
        }
        if (!vis[cara]) {
            montar_dag(cara);
        }
    }
}

void dfs2(int u, vector<int> &sccs, int it) {
    // acha os componentes conexos e os representantes deles
    vis[u]++;
    rep[u] = it;
    for (auto cara: rev[u]) {
        if (!vis[cara]) dfs2(cara, sccs, it);
    }
    sccs.push_back(u);
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

        arrive[i].first = 0;
        lft[i].first = 0;
        arrive[i].second = i;
        lft[i].second = i;
    }

    vector<int> stc;
    for (int i=0; i <= n; i++) {
        if (!vis[i]) dfs1(i, stc);
    }

    vis.assign(n + 1, 0);

    vector<int> stc2 = stc;
    while ((int) stc.size()){
        int cara = stc.back();
        stc.pop_back();
        vector<int> sccs;
        if (!vis[cara]) dfs2(cara, sccs, cara);
    }

    vis.assign(n + 1, 0);
    while (stc2.size()) {
        // fazer o caminho do grafo normal a partir da folha montando o track
        int u = stc2.back();
        stc2.pop_back();
        montar_dag(u);
    }

    set<int> picos;
    set<int> sinks;
    cout << "printando os poços e altos -> " << endl;
    for (int i=1; i <= n; i++) {
        if (arrive[rep[i]].first > 0 && lft[rep[i]].first == 0) {
            /* cout << rep[i] << " é poço " << endl; */
            sinks.emplace(rep[i]);
        } else if (arrive[rep[i]].first == 0 && lft[rep[i]].first > 0) {
            /* cout << rep[i] << "é pico" << endl; */
            sinks.emplace(rep[i]);
        }
    }

    vector<int> resp;
    int pc = *picos.begin();
    int pl = *dag[pc].begin();

    for (auto cara: sinks) {
    }
    for (auto cara: picos) {
        
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
