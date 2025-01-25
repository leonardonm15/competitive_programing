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

void dfs(int u, int& counter) {
    if (!vis[u]) vis[u]++;
    counter++;
    for (auto v: adj[u]) if (!vis[v]) dfs(v, counter);
}

void pref(vector<pair<int, int>>& ref) {
    cout << "------REF-------" << endl;
    for (auto [f, s]: ref) cout << f << " " << s << endl;
    cout << "----------------" << endl;
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

    sort(ref.rbegin(), ref.rend());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    int a = ref[0].second;
    ref[0].first = 0;
    int b = -1;

    sort(ref.begin(), ref.end(), check);

    for (auto v: adj[a]) ref[v - 1].first--;

    sort(ref.rbegin(), ref.rend());

    int i = 0;
    while(i < n && ref[i].second == a) i++;
    b = ref[i].second;
    vis[a]++;
    vis[b]++;

    /* pref(ref); */
    /* cout << "a -> " << a << endl; */
    /* cout << "b -> " << b << endl; */

    int resp = 0;
    for (auto u: nodes) {
        if (!vis[u]) {
            int counter = 0;
            resp++;
            dfs(u, counter);
        }
    }
    
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
