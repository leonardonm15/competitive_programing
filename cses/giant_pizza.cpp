#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e6 + 5;
vector<int> vis(N);
vector<int> rep(N);
vector<int> g[2 * N];
vector<int> gt[2 * N];

void dfs(int u, vector<int>& stc) {
    vis[u]++;
    for (auto v: g[u]) if (!vis[v]) {
        dfs(v, stc);
    }
    stc.push_back(u);
}

void dfst(int u, int group) {
    vis[u]++;
    rep[u] = group;
    for (auto v: gt[u]) if (!vis[u]) {
        dfst(v, group);
    }
}

void solve () {
    int n, m; cin >> n >> m;
    for (int i=0; i < n; i++) {
        int sx, sy;
        char a, b;
        int x, y;
        cin >> a >> x >> b >> y;
        sx = (a == '+' ? -1 : 1);
        sy = (b == '+' ? -1 : 1);

        g[2 * x + sx].push_back(2 * y + !sy); // (a -> ~b) 
        g[2 * y + sy].push_back(2 * x + !sx); // (b -> ~a)
        gt[2 * x + !sx].push_back(2 * y + sy);
        gt[2 * y + !sy].push_back(2 * x + sx);
    }

    vector<int> stc;
    for (int i=1; i <= m; i++) {
        if (!vis[i]) dfs(i, stc);
    }

    vis.assign(2 * m + 1, 0);
    int group = 1;
    while ((int)stc.size()) {
        int u = stc.back();
        cout << "U -> " << u << endl;
        stc.pop_back();
        if (!vis[u]) dfst(u, group++);
    }

    for (int i=1; i <= 2 * m; i++) {
        cout << rep[i] << " ";
    }
    cout << endl;

    vector<char> resp(m, '-');
    for (int i=1; i <= 2 * m; i += 2) {
        /* cout << "I -> " << i << endl; */
        /* cout << "rep[i] -> " << rep[i] << endl; */
        /* cout << "resp[i + 1] -> " << rep[i + 1] << endl; */
        if ((rep[i] == rep[i + 1]) && rep[i]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        resp[i/2] = (rep[i] < rep[i + 1] ? '+' : '-');
    }

    for (auto cara: resp) cout << cara << " ";
    cout << endl;
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
