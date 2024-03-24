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
int tic = 0;

void dfs1(int u) {
    vis[u]++;
    for (auto cara: adj[u]) {
        if (!vis[cara]) {
            dfs1(cara);
            sub[u] += sub[cara];
            if (sub[u] >= (tg - 1)) {
                resp = min({sub[u], resp, sub[cara]});
                sub[cara] = 0;
                sub[u] -= sub[cara];
            }
        }
    }
    
    /* if (sub[u] >= (tg - 1)) { */
    /*     tic++; */
    /*     resp = min({sub[u], resp, sub[); */
    /*     sub[u] = 0; */
    /*     return 0; */
    /* } */

    /* return sub[u]; */
}

/* int tc = 0; */

void solve () {
    /* tc++; */
    int n, k; cin >> n >> k;

    for (int i=0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    tg = (n/(k + 1)) + 1;

    dfs1(1);
    
    cout << resp << endl;

    /* int s = 0; */
    /* bool flag = false; */
    /* if (sub[1] >= tg) { */
    /*     for (auto cara: adj[1]) { */
    /*         s = max(sub[cara], s); */
    /*     } */

    /*     cout << min(s, sub[1] - s) << endl; */
    /*     flag = true; */
   /* } */

    /* if (!flag) { */
    /*     resp = min(resp, sub[1]); */
    /*     cout << resp << endl; */
    /* } */

    for (int i=0; i <= n; i++) {
        adj[i].clear();
        vis[i] = 0;
        sub[i] = 1;
        tic = 0;
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
