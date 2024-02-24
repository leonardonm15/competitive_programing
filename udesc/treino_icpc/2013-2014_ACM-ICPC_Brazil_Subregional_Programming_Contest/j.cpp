#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long
#define ii pair<int, int>

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int MAX = 1e4 + 5;
const int INF = 1e9 + 9;
vector<int> resp;

vector<ii> adj[MAX];
vector<int> dist(MAX);

int dk(int s, int t) {
    priority_queue<ii, vector<ii>, greater<ii>> fila;
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    fila.emplace(dist[s], s);
    while (!fila.empty()) {
        auto [d, u] = fila.top();
        fila.pop();
        if (u == t) {
            return dist[t];
        }
        if (d != dist[u]) {
            continue;
        }
        for (auto [w, v] : adj[u]) {
            if (dist[v] > d + w) dist[v] = d + w;
            fila.emplace(dist[v], v);
        }
    }

    return -1;
}

void solve () {
    
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
