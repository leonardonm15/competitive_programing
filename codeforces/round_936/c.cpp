#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;
vector<int> adj[N];
int comp = 1;

int dfs(int u, int p, int mx) {
    int s = 1;
    vector<pair<int, int>> r;
    for (auto cara: adj[u]) if (cara != p) {
        s += dfs(cara, u, mx);
    }

    if (s >= mx) {
        comp++;
        return 0;
    }

    return s;
}

void solve () {
    int n, k; cin >> n >> k;
    for (int i=0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int l = 0;
    int r = n;
    int resp = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int ans = dfs(1, -1, mid);
        int comp = 1;
        if (ans >= resp && comp > k) {
            resp = ans;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << resp << endl;

    for (int i=0; i <= n; i++) {
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
