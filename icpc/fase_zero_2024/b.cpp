#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;
int vis[N];
int am = 0;
vector<pair<int, int>> adj[N];

void dfs(int u, int mid) {
    vis[u]++;
    am++;
    for (auto [w, v]: adj[u]) {
        if (!vis[v] && w <= mid) dfs(v, mid);
    }
}

bool check(int mid, int n, int k) {
    am = 0;
    // cout << "dfs -> " << endl;
    dfs(1, mid);
    // cout << "--------------" << endl;
    // cout << "mid -> " << mid << endl;
    // cout << "am -> " << am << endl;
    for (int i=0; i <= n; i++) vis[i] = 0;
    return am >= k;
}

void solve () {
    int n, m, k; cin >> n >> m >> k;
    for (int i=0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int l = 0;
    int r = 8760;
    int ans = 0;
    // cout << "opa -> " << check(3, n, k) << endl;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, n, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
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

