#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


void solve () {
    int n, k; cin >> n >> k;
    map<int, vector<int>> mod;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        mod[num % k].push_back(num);
    }

    int resp = 0;
    int c = 0;
    for (auto& [m, vec]: mod) {
        sort(vec.rbegin(), vec.rend());
        /* cout << "vec -> "; */
        /* for (auto cara: vec) cout << cara << " "; */
        /* cout << endl; */
        if (!(vec.size()&1)) {
            for (int i = 1; i < vec.size(); i += 2) resp += vec[i - 1] - vec[i];
        } else {
            c++;
            if (c == 2) {
                cout << -1 << endl;
                return;
            }

            if (vec.size() == 1) continue;
            vector<vector<int>> dp(vec.size() + 1, vector<int>(2, 1e18));
            dp[0][0] = 0;
            dp[0][1] = 0;
            dp[1][0] = vec[0] - vec[1];
            dp[1][1] = vec[0] - vec[1];
            for (int i = 2; i < vec.size(); i++) {
                int nao_pula = vec[i - 1] - vec[i];
                assert(nao_pula >= 0);
                dp[i][0] = nao_pula + dp[i - 2][0]; // nao pegar aresta repetida por isso o - 2
                dp[i][1] = min(nao_pula + dp[i - 2][1], dp[i - 1][0]);
            }
            resp += dp[vec.size() - 1][1];
        }
        /* cout << "resp -> " << resp << endl; */
    }

    cout << resp / k << endl;
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
