#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

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
