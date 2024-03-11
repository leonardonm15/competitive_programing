#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m, u; cin >> n >> m >> u;
    vector<set<int>> dp(m + 2);
    dp[0].emplace(u - 1);
    for (int i=0; i < m; i++) {
        int jmp; cin >> jmp; char c; cin >> c;
        for (auto atual: dp[i]) {
            int v;
            if (c != '?') v = c - '0';
            if (c == '?' || v == 0) {
                int b = atual + jmp;
                b = b % n;
                dp[i + 1].emplace(b);
            } 
            if (c == '?'|| v&1) {
                int b = atual - jmp;
                if (atual - jmp < 0) {
                    /* cout << "b -> " << n - (jmp - atual + 1) << endl; */
                    dp[i + 1].emplace((n - 1) - (jmp - (atual + 1)));
                } else {
                    /* cout << "b -> " << b << endl; */
                    dp[i + 1].emplace(b);
                }
            }
        }
    }

    cout << dp[m].size() << endl;
    for (auto cara: dp[m]) {
        cout << cara + 1 << " ";
    }
    cout << endl;
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
