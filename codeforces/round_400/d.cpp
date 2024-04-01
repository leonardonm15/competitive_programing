#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 2e5 + 5;
vector<int> g[N];
vector<int> tg[N];
vector<int> vis(N);

void solve () {
    int n, m; cin >> n >> m;
    vector<int> status(n);
    for (int i=0; i < n; i++) cin >> status[i];
    for (int i=0; i < m; i++) {
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
