#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 2e5 + 5;

vector<pair<int, int>> inp(maxn);
vector<int> pai(maxn);
vector<int> adj[maxn];
vector<bool> vis(maxn);
vector<int> tamanho(maxn, 1);
vector<int> queries;
set<int> sorted_q;
int componentes = 1;

void inicializa_dsu(int n) {
    for (int i=0; i < n; i++) pai[i] = i;
}

int find(int n) {
    if (pai[n] == n) return n;
    return find(pai[n]);
}

void uniao(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return;
    if (tamanho[rb] > tamanho[ra]) swap(ra, rb);
    pai[rb] = ra;
    tamanho[ra] += tamanho[rb];
}

void solve () {
    int n, m; cin >> n >> m;
    int res = n;
    for (int i=1; i <= m; i++) {
        int a, b; cin >> a >> b;
        inp[i] = make_pair(a, b);
    }
    int q; cin >> q;
    for (int i=0; i < q; i++) {
        int num; cin >> num;
        queries.push_back(num);
        sorted_q.insert(num);
    }
    inicializa_dsu(n + 1);
    for (int i=1; i <= m; i++) {
        if (sorted_q.size() > 0 && i == *sorted_q.begin()) {
            sorted_q.erase(sorted_q.begin());
            continue;
        }
        int a = find(inp[i].first);
        int b = find(inp[i].second);
        if (a != b) res--;
        uniao(a, b);
    }
    vector<int> output;
    for (int i= q-1; i >= 0; i--){
        int a = find(inp[queries[i]].first);
        int b = find(inp[queries[i]].second);
        output.push_back(res);
        if (a != b) res--;
        uniao(a, b);
    }
    reverse(output.begin(), output.end());
    for (auto i: output) {
        cout << i << " ";
    }
    cout << endl;
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
