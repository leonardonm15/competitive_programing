#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int C = 500; //
const int S = 86400 // numero de segundos em um dia
                    //

vector<int> adj[C]; // {cidade{segundos{eventos}}}
int am_c[C]; // ammout saidas por cidade
vector<int> vis

void solve () {
    int n, m; cin >> n >> m; // cidades arestas
    int o_tot = m;
    vector<tuple<int, int, int, int>> inp;

    for (int i=0; i < n; i++) {
        int o, s, d, e; cin >> o >> s >> d >> e; // origem destino start finish
        adj[o].push_back(d);
        am[o]++;
        inp.push_back({s, f, o, d});
    }

    sort(inp.begin(), inp.end());

    for (auto [s, f, o, d]: inp) {
        
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
