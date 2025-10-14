#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;
const int LN = 20;
const int INF = 1e9;

int bl[LN][N];
vector<int> adj[N];
int deph[N];

void deph_dfs(int u, int p, int d) {
    bl[0][u] = p;
    for (int i = 1; i < LN; i++) {
        bl[i][u] = bl[i - 1][bl[i - 1][u]];
    }

    for (auto v: adj[u]) if (v != p) {
        deph_dfs(v, u, d + 1);
    }

    deph[u] = d;
}

int soldiers[N];
vector<int> got_soldiers[N];
int spl[N];
int md = -INF;
void soldier_per_layer(int u, int p, int d) {

    for (auto v: adj[u]) if (p != v) {
        soldier_per_layer(v, u, d + 1);
    }

    if (soldiers[u]) {
        got_soldiers[d].push_back(u);
        spl[d] += soldiers[u];
        md = max(d, md);
    }
}

int lca(int u, int v) {
    int au = u;

    if (u == v) return u;

    for (int i = 19; i >= 0; i--) {
        if (bl[i][au] != bl[i][v]) {
            au = bl[i][au];
        }
    }

    return bl[0][au];
}

pair<int, int> calc_subtree(int u) {
    /* cout << "u -> " << u << endl; */
    soldier_per_layer(u, u, 0);
    md++;
    /* cout << "soldiers_per_layer -> "; */
    /* for (int i = 0; i <= max_layer; i++) { */
    /*     cout << spl[i] << " "; */
    /* } */
    /* cout << endl; */


    vector<int> max_value_layers;
    int mv = 0;
    for (int i = 0; i <= md; i++) {
        if (spl[i] > mv) {
            max_value_layers.clear();
            max_value_layers.push_back(i);
            mv = spl[i];
        } else if (spl[i] == mv) {
            max_value_layers.push_back(i);
        }
        /* cout << "---------------------" << endl; */
        /* cout << "i -> " << i << endl; */
        /* cout << "spl[i] -> " << spl[i] << endl; */
        /* cout << "max_value_layers -> "; */
        /* for (auto y: max_value_layers) { */
        /*     cout << y << " "; */
        /* } */
        /* cout << endl; */
    }

    int ammount_of_rounds = 1e9;
    for (auto layer: max_value_layers) {
        int fs = got_soldiers[layer][0];
        int lowest_lca_height = 1e9;
        for (auto soldier: got_soldiers[layer]) {
            int lca_soldiers = lca(soldier, fs);
            lowest_lca_height = min(lowest_lca_height, deph[lca_soldiers]);
        }
        
        ammount_of_rounds = min(ammount_of_rounds, deph[fs] - lowest_lca_height);
    }

    for (int i = 0; i <= md; i++) {
        got_soldiers[i].clear();
        spl[i] = 0;
    }
    md = -INF;

    return {mv, ammount_of_rounds};
}

void solve () {
    int n; cin >> n;

    for (int i = 2; i <= n; i++) cin >> soldiers[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < LN; j++) {
            bl[j][i] = -1;
        }
    }

    deph_dfs(1, 1, 0);

    /* for (int u = 1; u <= n; u++) { */
    /*     cout << u << " -> "; */ 
    /*     for (int j = 0; j < LN; j++) { */
    /*         cout << bl[j][u] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    int most_soldiers = -1;
    int min_rounds = 1e9;
    for (auto v: adj[1]) {
        pair<int, int> c = calc_subtree(v);
        if (c.first >= most_soldiers) {
            min_rounds = c.second;
            most_soldiers = c.first;
        }
    }

    cout << most_soldiers << " " << min_rounds + 1 << endl;

}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
