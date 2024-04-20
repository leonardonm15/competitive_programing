#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
map<pair<int, int>, int> vis;
map<pair<int, int>, vector<pair<int, int>>> adj;

void dfs(pair<int, int> u, int cc) {
    vis[u] = cc;
    for (auto v: adj[u]) {
        if (vis[v] == 0) dfs(v, cc);
    }
}

void solve () {
    int n, q, d; cin >> n >> q >> d;
    vector<pair<int, int>> ops = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    vector<pair<int, int>> sedes(n + 5);

    for (int i=0; i < n; i++) {
        int x, y; cin >> x >> y;
        sedes[i + 1] = {x, y};
        int k = d; // distancia maxima
        while (k) {
            int u = k;
            int v = 0;
            int comp = k;
            while (v != comp + 1) {
                for (auto [a, b]: ops) {
                    adj[make_pair(x, y)].push_back(make_pair((x + u) * a, (y + v) * b));
                    adj[make_pair((x + u) * a, (y + v) * b)].push_back(make_pair(x, v));
                }
                u--;
                v++;
            }
            k--;
        }
    }

    for (int i=1; i <= n; i++) {
        if (!vis[sedes[i]]) {
            dfs(sedes[i], i);
        }
    }

    while (q--) {
        int a, b; cin >> a >> b;
        cout << (vis[sedes[a]] == vis[sedes[b]] ? "S" : "N") << endl;
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
