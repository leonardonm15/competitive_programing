#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int C = 500; //
const int S = 86400 // numero de segundos em um dia
                    //

vector<vector<vector<int>>>> adj(C, vector<int>(S)); // {cidade{segundos{eventos}}}

void solve () {
    int n, m; cin >> n >> m; // cidades arestas
    vector<tuple<int, int, int, int>> inp;

    for (int i=0; i < n; i++) {
        int o, s, d, e; cin >> o >> s >> d >> e;
        inp.push_back({o, d, s, e});
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
