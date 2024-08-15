#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int pai[N];
int sz[N];

int find(int u) {
    if (pai[u] != u) return find(pai[u]);
    else return u;
}

void unite(int a, int b) {
    int u = find(a);
    int v = find(b);

    if (u == v) return;

    if (sz[v] > sz[u]) swap(u, v);

    pai[v] = u;
    sz[u] += sz[v];
}



void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        pai[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        unite(u, v);
    }

    set<int> s;

    for (int i = 1; i <= n; i++) s.emplace(find(i));

    int resp = 1;
    // cout << "opa -> " << endl;
    for (auto c: s) {
        // cout << c << " " << sz[c] << endl;
        resp *= sz[c];
        resp %= MOD;
    }

    cout << resp << endl;

}

signed main() {
    solve();
}
