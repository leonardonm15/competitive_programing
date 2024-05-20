#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int N = 50 + 5;
int dp[N];

vector<int> adj[N];
vector<pair<int, int>> op;
int x, n;

int dfs(int u, int d, int f) {
    if (u > n) return f;
    if (d < 0) return 0;
    if (dp[u] != -1) return dp[u];
    int resp = 0;
    for (auto v: adj[u]) {
        int cd = (v - u) * x;
        resp = max({dfs(u + 1, d - op[u].first + cd, f + op[u].second), dfs(u + 1, d + x, f), f});
    }

    return dp[u] = resp;
}

void solve () {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> op;
    for (int i=1; i <= n; i++) {
        int a, b; cin >> a >> b;
    }

    for (int i=1; i <= n; i++) {
        for (int j=i + 1; j <= n; j++) {
            adj[i].push_back(j);
        }
    }

    int ini = 0;
    int resp = 0;
    for (int i=0; i <= n; i++) {
        max(resp, dfs(i, ini, 0));
        ini += x;
    }

    cout << resp << endl;
    op.clear();
    for (int i=0; i <= n; i++) {
        dp[i] = -1;
        adj[i].clear();
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
