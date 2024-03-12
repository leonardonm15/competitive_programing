#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int m, n, k, d; cin >> m >> n >> k >> d;
    vector<int> resps;
    multiset<int> mn;
    vector<int> dp(n);
    dp[0] = 1;
    dp[n - 1] = 1;

    for (int i=0; i < m; i++) {
        vector<int> arr(n);
        for (int i=0; i < n; i++) cin >> arr[i];
        // custo do meu cara + custo pra chegar no menor cara que eu alcanço
        for (int i=0; i < d; i++) {
            mn.emplace(arr[i]);
        }

        for (int i=0; i < n; i++) {
            mn.emplace(arr[i]);
            if (mn.size() > d) mn.erase(arr[i - d]);

            
        }
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
