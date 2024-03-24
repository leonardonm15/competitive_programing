#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;

vector<int> adj[N];
vector<int> sub(N, 1);
vector<int> vis(N);
int resp = 1e9 + 5;
int tg;

int dfs1(int u) {
    vis[u]++;
    vector<pair<int, int>> r;
    for (auto cara: adj[u]) {
        if (!vis[cara]) {
            int cc = dfs1(cara);
            r.push_back({cc, cara});
            sub[u] += cc;
        }
    }
    sort(r.rbegin(), r.rend());
    for (auto [cc, i]: r) {
        if (sub[u] > tg) {
            sub[u] -= cc;
            resp = min({sub[u], resp, cc});
            sub[i] = 0;
        }
    }

    return sub[u];
}

void solve () {
    int n, k; cin >> n >> k;
    vector<int> r;
    for (int i=0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        r.push_back(a);
        r.push_back(b);
    }

    tg = (n/(k + 1));

    dfs1(1);

    for (auto cara: adj[1]) {
        if (sub[cara] == 0) continue;
        resp = min(sub[cara], sub[1]);
    }

    resp = min(resp, sub[1]);

    cout << resp << endl;

    for (int i=0; i <= n; i++) {
        adj[i].clear();
        vis[i] = 0;
        sub[i] = 1;
    }
    resp = 1e9 + 5;
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
