#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;

vector<int> adj[N];
vector<int> radj[N];
int sz[N];
int vis[N];
int dp[N];
vector<int> ts;

void dfs(int u) { // toposort
    vis[u]++;
    for (auto v: adj[u]) if (!vis[v]) dfs(v);
    ts.push_back(u);
}

void paint(int u, int c) { // cores e tamanhos de ciclos
    vis[u] = c;
    sz[c]++;
    for (auto v: radj[u]) if (!vis[v]) paint(v, c);
}

int calc(int u) { // longest path
    if (dp[u]) return dp[u];
    if (sz[vis[u]] > 1) return 0;
    if (adj[u].size() == 0) return 1;
    int k = 0;
    for (auto v: adj[u]) {
        k = max(k, calc(v));
    }

    return dp[u] = k + 1;
}

void solve () {
    int n; cin >> n;
    vector<pair<int, int>> lm(n);  // quantos caras me dao presente

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        lm[num - 1].first++;
        lm[i].second = i + 1;
        adj[i + 1].push_back(num);
        radj[num].push_back(i + 1);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    for (int i = 0; i <= n; i++) vis[i] = 0;

    reverse(ts.begin(), ts.end());

    int color = 1;
    for (auto c: ts) {
        if (!vis[c]) paint(c, color++);
    }

    sort(lm.begin(), lm.end());

    int resp = 0;
    for (int i = 0; i < n; i++) {
        if (lm[i].first == 0) {
            resp = max(resp, calc(lm[i].second));
        }
    }

    cout << resp + 2 << endl;

    ts.clear();
    for (int i = 0; i <= n + 1; i++) {
        adj[i].clear();
        radj[i].clear();
        vis[i] = 0;
        sz[i] = 0;
        dp[i] = 0;
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
