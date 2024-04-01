#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;
vector<int> g[2 * N];
vector<int> tg[2 * N];

void solve () {
    int n, m; cin >> n >> m;
    for (int i=0; i < n; i++) {
        int sx, sy;
        char a, b; cin >> a >> b;
        int x, y; cin >> x >> y;
        cin >> a >> x >> b >> y;
        if (a == '+') sx = 1;
        if (a == '-') sx = -1;

        if (b == '+') sy = 1;
        if (b == '-') sy = -1;

        g[2 * x + sx].push_back(2 * y + !sy);
        g[2 * y + sy].push_back(2 * x + !sx);

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
