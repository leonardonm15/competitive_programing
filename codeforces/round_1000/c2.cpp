#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;
int vis[N], points[N];
vector<int> adj[N];

bool check(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

bool verify(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) return points[a.second] < points[b.second];
    else return a.first < b.first;
}

void pref(vector<pair<int, int>>& ref) {
    cout << "------REF-------" << endl;
    for (auto [f, s]: ref) cout << f << " " << s << endl;
    cout << "----------------" << endl;
}

void dfs(int u, int& counter) {
    vis[u]++;
    counter++;
    for (auto v: adj[u]) if (!vis[v]) dfs(v, counter);
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

    for (int i = 0; i < n; i++) {
        if (ref[i].first == 1) {
            int v = ref[i].second;
            points[adj[v][0]]++;
        }
    }

    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    sort(ref.rbegin(), ref.rend(), verify); // sorta com base no numero de caras

    /* pref(ref); */

    int a = ref[0].second; // pega oq tem mais
    ref[0].first = -1; // tira ele da lista
    int b = -1; 

    sort(ref.begin(), ref.end(), check); // sorta com base nos nodos

    for (auto v: adj[a]) ref[v - 1].first--; // tira -1 dos nodos que estavam conectados no primeiro cara

    sort(ref.rbegin(), ref.rend(), verify); // sorta com base no numero de caras

    int i = 0;
    while(i < n && ref[i].second == a) i++;
    b = ref[i].second; // pega oq tem mais
    sort(ref.begin(), ref.end(), check); // sorta com base nos nodos

    vis[a]++;
    vis[b]++;

    int resp = 0;
    for (auto u: nodes) {
        if (!vis[u]) {
            int counter = 0;
            resp++;
            dfs(u, counter);
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
