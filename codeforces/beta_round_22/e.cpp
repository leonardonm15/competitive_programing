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
vector<int> rep(N); // representante
vector<int> track(N, -1);
/* vector<set<pair<int, int>>> resp(N); */
vector<pair<int, int>> lft(N); // quantidade de caras que tao saindo de alguem
vector<pair<int, int>> arrive(N); // quantidade de caras que tao entrando em alguem

void montar_dag(int u) {
    // monta a dag com os representantes de cada SCC 
    // + monta a DAG
    vis[u]++;
    /* cout << "U -> "<< u << endl; */
    for (auto cara: adj[u]) {
        if (!vis[cara]) {
            if (rep[cara] != rep[u]) {
                dag[u].emplace(cara);
                lft[u].first++;
                arrive[cara].first++;
            }
            montar_dag(cara);
        }
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
        stc2.pop_back();
        montar_dag(u);
    }

    cout << "arrive -> ";
    for (int i=1; i <= n; i++) {
        cout << arrive[i].first << " ";
    }
    cout << endl;


    cout << "lft ->   ";
    for (int i=1; i <= n; i++) {
        cout << lft[i].first << " ";
    }
    cout << endl;

    cout << "printando os poços e altos -> " << endl;
    for (int i=1; i <= n; i++) {
        if (arrive[i].first > 0 && lft[i].first == 0) {
            cout << i << " é poço " << endl;
        } else if (arrive[i].first == 0 && lft[i].first > 0) {
            cout << i << "é pico" << endl;
        }
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
