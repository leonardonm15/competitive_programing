#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;

map<int, int> pos;
vector<int> cuts;
set<int> dp[N];

int dfs(int i, int m, int s, int n) {
    if (i == (int) n) return 0;
    if (dp[i][s]) return pos[m];

    int now = cuts[i];

    if (now > m) {
        
    }
}

void solve () {
    int n, m, q; cin >> n >> m >> q;
    cuts.resize(q);

    map<int, int> pos;
    pos[m]++;

    for (int i = 0; i < q; i++) cin >> cuts[i];


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
