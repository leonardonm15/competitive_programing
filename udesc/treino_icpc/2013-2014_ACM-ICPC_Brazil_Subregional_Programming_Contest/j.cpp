#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define pii pair<int, int>
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     


const int N = 2e4 + 5;
const int M = 1e5 + 5; 
vector<pii> adj[N];

void solve () {
    int n, m, q; cin >> n >> m >> q;
    // teste
    vector<tuple<int, int, int>> edg;
    for (int i=0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edg.push_back({w, a, b});
    }

    sort(edg.rbegin(), edg.rend());
    /* cout << "--------" << endl; */
    for (auto [w, a, b]: edg) {
        /* cout << w << " "; */
        if (adj[a].size() == 0 || adj[b].size() == 0) {
            /* cout << a << " " << b << " " << w << endl; */
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
	}
    }
    cout << endl;

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
