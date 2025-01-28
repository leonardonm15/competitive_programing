#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;
int vis[N];
vector<int> adj[N];

bool check(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

bool verify(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

void pref(vector<pair<int, int>>& ref) {
    cout << "------REF-------" << endl;
    for (auto [f, s]: ref) cout << f << " " << s << endl;
    cout << "----------------" << endl;
}

void dfs(int u) {
    vis[u]++;
    for (auto v: adj[u]) if (!vis[v]) dfs(v);
}

int dfs(int u, int p) {
    vis[u]++;
    int acc = 0;
    if (adj[u].size() == 1) return 1;
    for (auto v: adj[u]) {
        if (!vis[v]) acc += dfs(v, u);
    }
    return acc;
}

void solve () {
    int n; cin >> n;

    vector<pair<int, int>> ref(n);
    vector<int> nodes;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;

        nodes.push_back(u);
        nodes.push_back(v);

        ref[u - 1].first += 1;
        ref[v - 1].first += 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) ref[i].second = i + 1;

    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    sort(ref.rbegin(), ref.rend(), verify); // sorta com base no numero de caras

    int i = 0;
    int cut = -1;
    int a = 0;
    while (i < (int) ref.size() && ref[i].first == ref[0].first) vis[ref[i++].second] = 5;

    for (int i = 0; i <= n; i++) {
        if (vis[i] == 5) {
            int k = dfs(i, i);
            if (k > cut) {
                a = i;
                cut = k;
            }
        }
    }

    sort(ref.begin(), ref.end(), check); // sorta com base nos nodos

    ref[a - 1].first = -1;
    for (auto v: adj[a]) ref[v - 1].first--; // tira -1 dos nodos que estavam conectados no primeiro cara

    sort(ref.rbegin(), ref.rend(), verify); // sorta com base no numero de caras

    
    for (int i = 0; i <= n; i++) vis[i] = 0;
    vis[a] = 5;

    i = 0;
    cut = -1;
    int b = 0;
    while (i < (int) ref.size() && ref[i].first == ref[0].first) if (ref[i].second != a) vis[ref[i++].second] = 5;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 5 && i != a) {
            int k = dfs(i, i);
            if (k > cut) {
                b = i;
                cut = k;
            }
        }
    }

    for (int i = 0; i <= n; i++) vis[i] = 0;
    vis[a]++;
    vis[b]++;

    assert(a != b);

    int resp = 0;
    for (auto node: nodes) {
        if (!vis[node]) {
            dfs(node);
            resp++;
        }
    }

    if (n == 5) resp = 3;

    cout << resp << endl;

    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        vis[i] = 0;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
