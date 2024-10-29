#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int amigos, salas; cin >> amigos >> salas;
    vector<int> amigos_salas, perm;
    vector<vector<int>> dist(salas, vector<int>(salas));

    for (int i = 0; i < salas; i++) {
        int num; cin >> num;
        amigos_salas.push_back(num);
        if (num > 0 && i > 0) perm.push_back(i);
    }


    for (int i = 0; i < (salas * (salas - 1)) / 2; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        w *= 60;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    if (amigos_salas[0] == amigos) {
        cout << (amigos_salas[0] * 30 > 20 * 60 ? 0 : 1) << endl;
        return;
    }

    for (int i = 0; i < salas; i++) {
        for (int j = 0; j < salas; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    int k = perm.size();
    int resp = 1e18;
    do {
        int time = 0;
        time += 30 * amigos_salas[0];
        for (int i = 0; i < k; i++) {
            if (i == 0) time += dist[0][perm[i]] + 30 * amigos_salas[perm[i]];
            else time += dist[perm[i - 1]][perm[i]] + 30 * amigos_salas[perm[i]];
        }
        time += dist[perm[k - 1]][0];
        resp = min(resp, time);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << (resp > 20 * 60 ? 0 : 1) << endl;
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
