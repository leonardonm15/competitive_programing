#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

:eqw

void solve () {
    int n, q, d; cin >> n >> q >> d;
    map<tuple<int, int, int>, vector<int>> scc;
    vector<pair<int, int>> arr;
    for (int i=0; i < n; i++) {
        int x, y; cin >> x >> y;
        int b = 0;
        int c = d;
        // ve se o meu cara central é ponto de briga, se for junta na dsu os outros caras
        // dps disso marca em volta os pontos de briga da novo conjunto
        for (int i=1; i <= d; i++) {
            
        }
    }
    // faz uma dfs pega as ditancias pra sedes adj
    // se a sede adj tives dist eucl > limite nao coloca essa aresta
    // dps roda dfs dnv coloca os caras nos componentes deles
    // dps so responder
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
