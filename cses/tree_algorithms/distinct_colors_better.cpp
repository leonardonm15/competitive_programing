#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int N = 2e5 + 5;
int c[N], sz[N], f[N], ans[N];
int resp = 0;
vector<int> adj[N];

int size(int u, int p) {
    if (adj[u].size() == 0) return sz[u] = 1;

    for (auto v: adj[u]) if (v != p) sz[u] += size(v, u);

    for (int i=0; i < (int)adj[u].size(); i++) {
        if (adj[u][0] == p) swap(adj[u][0], adj[u][adj[u].size() - 1]);
        if (p != adj[u][i] && sz[adj[u][i]] > sz[adj[u][0]]) swap(adj[u][i], adj[u][0]);
    }

    return sz[u];
}

void add(int u, int p) {
    if (!f[c[u]]) resp++;
    f[c[u]]++;
    for (auto v: adj[u]) if (v != p) add(v, u);
}

void remove(int u, int p) {
    if (f[c[u]] == 1) resp--;
    f[c[u]]--;
    for (auto v: adj[u]) if (v != p) {
        remove(v, u);
    }
}

void dfs(int u, int p, bool is_big) {
    for (int i=1; i < adj[u].size(); i++) {
        if (adj[u][i] != p) {
            dfs(adj[u][i], u, 0);
            /* add(adj[u][i], u); */
            /* remove(adj[u][i], u); */
        }
    }

    if (adj[u].size() > 1) dfs(adj[u][0], u, 1); //  adj[u][0] != p
    
    for (int i=1; i < adj[u].size(); i++) {
        if (adj[u][i] != p) add(adj[u][i], u);
    }

    if (!f[c[u]]) resp++;
    f[c[u]]++;

    ans[u] = resp;
    if (!is_big) remove(u, p);
}

void solve () {
    int n; cin >> n;
    vector<int> b;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        c[i] = num;
        b.push_back(num);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());


    for (int i=0; i < n; i++) {
        int z = c[i];
        c[i] = lower_bound(b.begin(), b.end(), z) - b.begin();
    }

    for (int i=0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    size(1, -1);
    dfs(1, -1, 1);
    for (int i=1; i <= n; i++) cout << ans[i] << " ";
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
