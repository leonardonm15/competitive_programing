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
vector<pii> sources;
int vis[N];
int dist[N];
int pai[N];
bool flag = false;
bool evil = false;

void dfs(int u, int root, int price) {
    path.push_back(u);
    if (u == root && price < 0 && !evil) {
        evil = true;
        resp = path;
        return;
    }

    if (vis[u]) return;

    vis[u]++;
    for (auto [w, v]: adj[u]) {
        dfs(v, root, price + w);
    }

    path.pop_back();
}

void bellman_ford(int n) {

    for (int i = 0; i < n; i++) {
        for (auto [w, u, v]: edg) {
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    /* cout << "dist -> "; */
    /* for (int i = 1; i <= n; i++) { */
    /*     cout << dist[i] << " "; */
    /* } */
    /* cout << endl; */

    for (auto [w, u, v]: edg) {
        if (dist[u] < INF && dist[u] + w < dist[v]) {
            dist[v] = -INF;
            pai[v] = u;
        }
    }
}

void solve () {
    int n, m; cin >> n >> m;

    sources.resize(n);

    bool opa = false;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (u == v && w < 0 && !opa) {
            opa = true;
            cout << "YES" << endl;
            cout << u << " " << v << endl;
        }
        sources[v - 1].first++;
        edg.push_back({w, u, v});
        adj[u].push_back({w, v});
    }

    if (opa) return;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        sources[i - 1].second = i;
    }

    sort(sources.begin(), sources.end());

    dist[sources[0].second] = 0;

    for (auto [am, node]: sources) {
        if (!am) {
            dist[node] = 0;
        }
    }

    bellman_ford(n);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == -INF) {
            dfs(i, pai[i], 0);
            if (resp.size() == 0) {
                for (int i = 1; i <= n; i++) vis[i] = 0;
                continue;
            }
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
