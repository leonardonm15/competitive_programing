#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
vector<bool> vis(maxn);
vector<bool> mk(maxn, false);
int mais_fundo = 0;
int nmf = 1;

void dfs(int nd, int mf = 0) {
    if (mf > mais_fundo && mk[nd]) {
        mais_fundo = mf;
        nmf = nd;
    }
    vis[nd] = true;
    for(auto cara: adj[nd]) {
        if (!vis[cara]) dfs(cara, mf + 1);
    }
}


void solve () {
    int n, k; cin >> n >> k;
    for (int i=0; i <= n; i++) vis[i] = mk[i] = 0;
    for (int i=0; i <=n; i++) adj[i].clear();
    mais_fundo = 0;
    nmf = 1;
    for (int i=0; i < k; i++) {
        int num; cin >> num;
        mk[num] = true;
    }
    for (int i=0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for (int i=0; i <= n; i++) vis[i] = 0;
    mais_fundo = 0;
    dfs(nmf);
    cout << (mais_fundo + 1) / 2 << endl;
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
