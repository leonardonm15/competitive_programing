#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int maxn = 2e5 + 5;
vector<string> arr(1);
vector<int> vis(maxn);
vector<set<int>> adj(maxn);

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void dfs(int n, int p, int nvl) { 
    vis[n] = nvl;
    for (auto cara: adj[n]) {
        if (cara == p) continue;
        int ciclo = abs(vis[n] - vis[cara]) + 1;
        /* cout << "ciclo size -> " << ciclo << endl; */
        if (cara == n || (vis[cara] > 0 && cara != p && ciclo % 2 == 1 && ciclo >= 2)) {
            arr[0] = "No";
            return;
        } else if (vis[cara] > 0) return;
        dfs(cara, n, nvl + 1);
    }
}

void solve () {
    int n, m; cin >> n >> m;
    arr[0] = "Yes";
    vector<int> s;
    vector<int> t;
    for (int i=0; i < m; i++) {
        int num; cin >> num;
        s.push_back(num);
    }
    for (int i=0; i < m; i++) {
        int num; cin >> num;
        t.push_back(num);
    }
    for (int i=0; i < m; i++) {
        if (s[i] > n || t[i]  > n || s[i] == t[i]) {
            cout << "No" << endl;
            return;
        }
        adj[s[i]].emplace(t[i]);
        adj[t[i]].emplace(s[i]);
    }
    for (int i=0; i <= n; i++) {
        if (vis[i] == 0 && adj[i].size() != 0) {
            dfs(i, -1, 1);
        }
    }
    cout << arr[0] << endl;
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
