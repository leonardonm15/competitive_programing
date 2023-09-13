#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 2e5 + 5;
set<int> pai[maxn];
vector<int> tamanho(maxn, 1);

void inicializa_dsu(int n) {
    for (int i=0; i < n; i++) pai[i].insert(i);
}

int find(int n) {
    if (pai[n].lower_bound(n) == n) { // busca binaria dentro do set
        return n;
    }
    for (auto filho: pai[n]) {
        find(pai[filho])
    }
}

void solve () {

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
