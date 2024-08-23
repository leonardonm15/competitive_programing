#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
 
void solve(){
    int n, t; cin >> n >> t;
    map<int, vector<pair<int, int>>> mp;
 
    for (int i = 0; i < n; i++) {
        int np, tam, maj; cin >> np >> tam >> maj;
        mp[tam].push_back({np, maj});
    }
 
    int resp = 0;
    for (int i = 0; i < t; i++) {
        int tamd, tame; cin >> tamd >> tame;
        int tam = min(tame, tamd);
        if (mp[i + 1ll].size() == 0) continue;
        vector<pair<int, int>> &candidatos = mp[i + 1ll];
        vector<vector<int>> dp(candidatos.size() + 1, vector<int>(tam + 2, 0));
        int l = 1;

        for (auto &[pes, maj]: candidatos) {
            pes /= 2;
            for (int k = 1; k <= tam + 1; k++) {
                if (k - pes >= 1) dp[l][k] = max(dp[l - 1][k] + maj, dp[l - 1][k - pes]);
                else dp[l][k] = dp[l - 1][k];
            }
 
            l++;
        }

        resp += dp[l - 1][tam + 1];
    }
 
    cout << resp << endl;
}
 
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
