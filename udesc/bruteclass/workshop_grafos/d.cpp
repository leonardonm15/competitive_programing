#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 2e5 + 5;

vector<pair<int, int>> inp[maxn];
vector<int> pai(maxn);
vector<int> adj[maxn];
vector<bool> vis(maxn);
vector<int> tamanho(maxn, 1);
vector<int> queries;
set<int> sorted_q;
int componentes = 1;

void inicializa_dsu(int n) {
    for (int i=0; i < n; i++) pai[i] = i;
}

int find(int n) {
    if (pai[n] == n) return n;
    return find(pai[filho]);
}

int dfs(int n, int num) { // retorna o tamanho componente
    num++;
    vis[n] = true;
    for (auto v: adj[n]) {
        if (vis[v]) continue;
        dfs(v);
    }
    return num;
}

void solve () {
    int n, m; cin >> a >> b;
    for (int i=1; i <= m; i++) {
        int a, b; cin >> a >> b;
        inp[i] = {a, b};
    }
    // pega as quries sorta e pra poder montar o grafo sem fuder tudo, dps vai juntando na ordem certa
    int q; cin >> q;
    for (int i=0; i < q; i++) {
        int num; cin >> num;
        queries.push_back(num);
        sorted_q.insert(num);
    }
    // monta o grafo pulando as arestas "proibidas"
    for (int i=1; i <= m; i++) {
        if (i == *sorted_q.begin()) {
            sorted_q.erase(sorted_q.begin());
            continue;
        }
        int a = inp[i].first;
        int b = inp[i].second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // dfs pros caras pra achar a quantidade de componentes conexos, e tamanho dos componentes 
    int numero_componentes_conexos = 0;
    for (int i=1; i <= n; i++) {
        int num;
        if (vis[i] == false) {
            numero_componentes_conexos++;
            int size_comp = dfs(i, 0);
        }
    }
    // com as informações do dfs monta o dsu
    // como faz pra setar os filhos de cada nodo
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
