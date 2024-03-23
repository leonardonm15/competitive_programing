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

int dfs1(int u) {
    vis[u]++;
    for (auto cara: adj[u]) {
        if (!vis[cara]) {
            sub[u] += dfs1(cara);
        }
    }
    
    if (sub[u] >= (tg - 1)) {
        tic++;
        resp = min(sub[u], resp);
        sub[u] = 0;
        return 0;
    }

    return sub[u];
}

int tc = 0;

void solve () {
    tc++;
    int n, k; cin >> n >> k;
    vector<int> r;
    for (int i=0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        r.push_back(a);
        r.push_back(b);
    }
    /* if (tc == 23) { */
    /*     cout << n << "#" << k << "#" << r[0] << "#" << r[1] << "#" << r[2] << "#" << r[3] << "#" << r[4] << "#" << r[5] << "#" << r[6] << "#" << r[7] << "#" << r[8] << "#" << r[9] << "#" << r[10] << "#" << r[11] << endl; */
    /* } */

    tg = (n/(k + 1)) + 1;

    dfs1(1);

    /* cout << "sub -> "; */
    /* for (int i=1; i <= n; i++) cout << sub[i] << " "; */
    /* cout << endl; */

    int s = 0;
    bool flag = false;
    if (sub[1] > tg) {
        /* vector<int> v; */
        for (auto cara: adj[1]) {
            /* v.push_back(sub[cara]); */
            s = max(sub[cara], s);
        }

        /* sort(v.rbegin(), v.rend()); */
        /* for (int i=tic; i < k; i++) { */

        /* } */
        cout << min(s, sub[1] - s) << endl;
        flag = true;
    }

    if (!flag) {
        resp = min(resp, sub[1]);
        cout << resp << endl;
    }

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
