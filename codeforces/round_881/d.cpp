#include <bits/stdc++.h>

using namespace std;
#define int long long
//
const int maxn = 2e5 + 5;
vector<int> arr[maxn];
vector<int> valls(maxn);

int dfs(int pai, int nodo) {
    if (arr[nodo].size() == 1 && arr[nodo][0] == pai) {
        valls[nodo] = 1;
        return 1;
    }
    else for (auto cara: arr[nodo]) {
        if (cara != pai){
            valls[nodo] += dfs(nodo, cara);
        }
    }
    return valls[nodo];
}

void solve () {
    int n; cin >> n;
    for (int i=0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
    }
    dfs(-1, 1);
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        cout << (long long) valls[a] * valls[b] << endl;
    }
    
    for (int i=0; i <= n; i++) {
        arr[i].clear();
        valls[i] = 0;
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
