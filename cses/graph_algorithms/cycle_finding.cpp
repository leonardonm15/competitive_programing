#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>

const int N = 2505;
const int INF = 1e18;

vector<pii> adj[N];
/* vector<int> radj[N]; */
vector<tiii> edg;
vector<int> path;
vector<int> resp;
vector<pii> sources(N);
int vis[N];
int dist[N];
bool flag = false;
bool evil = false;

void dfs(int u, int root) {
    path.push_back(u);
    cout << "u -> " << u << endl;
    if (u == root && vis[u] && !evil) {
        evil = true;
        resp = path;
        return;
    }

    if (vis[u]++) return;

    vis[u]++;
    for (auto [w, v]: adj[u]) {
        if (dist[v] == -INF) dfs(v, root);
    }

    path.pop_back();
}

void bellman_ford(int n) {

    for (int i = 1; i < n; i++) {
        for (auto [w, u, v]: edg) {
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (auto [w, u, v]: edg) {
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = -INF;
                cout << " inf -> " << v << endl;
            }
        }
    }
}

void solve () {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        sources[v - 1].first++;
        edg.push_back({w, u, v});
        adj[u].push_back({w, v});
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        sources[i - 1].second = i;
    }

    sort(sources.begin(), sources.begin() + n);

    // se nao tem nenhuma source
    for (auto [am, node]: sources) {
        if (!am) {
            cout << "node -> " << node << endl;
            dist[node] = 0;
        }
    }

    bellman_ford(n);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == -INF) {
            dfs(i, i);
            cout << "YES" << endl;
            for (auto c: resp) cout << c << " ";
            cout << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
