#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int m, n, k, d; cin >> m >> n >> k >> d;
    vector<int> resps;

    for (int i=0; i < m; i++) {
        vector<int> arr(n);
        multiset<int> mn;
        vector<int> dp(n, 1e9 + 5);
        mn.emplace(1);
        dp[0] = 1;
        for (int i=0; i < n; i++) cin >> arr[i];
        // custo do meu cara + custo pra chegar no menor cara que eu alcanço

        for (int i=1; i < n; i++) {
            dp[i] = *(mn.begin()) + arr[i] + 1;
            mn.emplace(dp[i]);
            if (i - d - 1 >= 0) mn.erase(mn.find(dp[i - d - 1]));
        }

        resps.push_back(dp[n - 1]);
        /* cout << "dp -> "; */
        /* for (auto cara: dp) cout << cara << " "; */
        /* cout << endl; */
    }

    vector<int> pref(m + 1);
    int soma = 0;
    for (int i=1; i <= m; i++) {
        soma += resps[i - 1];
        pref[i] = soma;
        /* cout << pref[i] << " "; */
    }
    /* cout << endl; */

    int ans = 1e18 + 5;
    for (int i=1; i + k - 1 <= m; i++) {
        ans = min(ans, pref[i + k - 1] - pref[i - 1]);
    }

    cout << ans << endl;
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
