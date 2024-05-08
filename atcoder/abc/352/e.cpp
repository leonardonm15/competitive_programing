#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;
vector<int> sz(N);
vector<int> pai(N);
vector<int> soma_peso(N);

int find_pai(int n) {
    if (pai[n] != n) return find_pai(pai[n]);
    else return pai[n];
}

void merge(int a, int b, int w) {
    a = find_pai(a);
    b = find_pai(b);
    if (sz[a] < sz[b]) swap(a, b);
    if (pai[a] != pai[b]) {
        sz[a] += sz[b];
        soma_peso[a] += soma_peso[b] + w;
        pai[b] = a;
    }
}

void dsu_start(int n) {
    for (int i=1; i <= n; i++) {
        sz[i] = 1;
        pai[i] = i;
    }
}

void solve () {
    int n, m; cin >> n >> m;
    dsu_start(n + 2);
    vector<pair<int, vector<int>>> ed;

    while (m--) {
        int c, w; cin >> c >> w;
        pair<int, vector<int>> inp;
        inp.first = w;
        for (int i=0; i < c; i++) {
            int num; cin >> num;
            inp.second.push_back(num);
        }
        ed.push_back(inp);
    }

    sort(ed.begin(), ed.end());
    for (auto [w, edg]: ed) {
        for (int i=1; i < edg.size(); i++) {
            merge(edg[0], edg[i], w);
        }
    }

    int c = 0;

    /* cout << "pais -> "; */
    /* for (int i=0; i <= n; i++) cout << pai[i] << " "; */
    /* cout << endl; */

    for (int i=1; i <= n; i++) {
        if (pai[i] == i) c++;
        if (pai[i] == i && c == 2) {
            cout << -1 << endl;
            return;
        }
    }

    int a = find_pai(1);
    cout << soma_peso[a] << endl;
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
