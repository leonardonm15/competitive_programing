#include <bits/stdc++.h>

using namespace std;
// #define int long long

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
vector<int> sub(maxn);
int n;

void dfsz(int a) {
    sub[a] = 1;
    for (auto cara: adj[a]) {
        dfsz(cara);
        sub[a] += sub[cara];
    }
}

int dfs(int a, int mx) {
    multiset<pair<int, int>> now;
    int resp = 0;
    // montando array sortado subarvores
    for (auto cara: adj[a]) now.emplace(sub[cara], cara);

    while (now.size() > 1) {
        // tirando um par de nodos do maior e da segunda maior subarvore
        auto [i, v] = *rbegin(now);
        auto [j, w] = *(++rbegin(now));
        now.erase(--end(now));
        now.erase(--end(now));
        sub[v]--;
        sub[w]--;
        resp++;
        // verifica se ainda tem nodos restantes nas subarvores reduzidas
        if (i > 1) now.emplace(i - 1, v);
        if (j > 1) now.emplace(j - 1, w);
    }

    int best = 0;
    if (now.size()) {
        best = dfs(begin(now)->second, begin(now)->first / 2);
    }
    return min(resp + best, mx);
}

void solve () {
    int n; cin >> n;
    for (int i=1; i < n; i++) {
        int num; cin >> num;
        num--;
        adj[num].emplace_back(i);
    }

    dfsz(0);
    cout << dfs(0, n) << endl;

    for (int i=0; i <= n + 5; i++) {
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

