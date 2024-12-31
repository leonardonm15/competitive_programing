#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    // kosaraju pra achar os ciclos no grafo
    //
    // dps de achar os ciclos acha os nodos que nao tem pai - toposort
    // dps chama dp de longest path usando o a quantidade de plushies pra esses caras que nao tem pai
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
            cout << i + 1 << " " << num << endl;
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
