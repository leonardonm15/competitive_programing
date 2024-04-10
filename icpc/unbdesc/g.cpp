#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5 + 5;
vector<int> diretorios[mx];
vector<int> n_arq(mx);
vector<int> visitados(mx);

void dfs(int k, long long& soma) {
    soma += n_arq[k];
    n_arq[k] = 0;
    visitados[k]++;
    for (auto dirs: diretorios[k]) {
        if (visitados[dirs] > 0) continue;
        dfs(dirs, soma);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int dir, arq; cin >> dir >> arq;
    int n_dir = 2;
    for (int i=1; i < dir; i++){ 
        int diret; cin >> diret; 
        diretorios[diret].push_back(n_dir);
        n_dir++;
    }
    for(int i=0; i < arq; i++) {
        int arquivo; cin >> arquivo;
        n_arq[arquivo]++;
    }
    int t; cin >> t;
    while(t--) {
        long long soma = 0;
        int k; cin >> k;
        dfs(k, soma);
        cout << soma << endl;
    }
}

