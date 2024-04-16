#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 4000 + 5;
vector<int> adj[N];
vector<int> vis(N);
vector<pair<int, int>> dp(N);
string s;
int resp = 0;

void dfs(int u) {
    vis[u]++;
    for (auto v: adj[u]) {
        if (!vis[v]) {
            dfs(v);
            dp[u].first += dp[v].first;
            dp[u].second += dp[v].second;
        }
    }

    /* cout << "===========" << endl; */
    /* cout << "U -> " << u << endl; */
    /* cout << "dp[u].first -> " << dp[u].first << endl; */
    /* cout << "dp[u].second ->"  << dp[u].second << endl; */
    if (dp[u].first == dp[u].second) resp++;
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=1; i < n; i++) {
        int num; cin >> num;
        /* cout << "num -> " << num << endl; */
        adj[i + 1].push_back(num);
        adj[num].push_back(i + 1);
    }

    cin >> s;
    /* cout << "s -> " << s << endl; */
    for (int i=1; i <= n; i++) {
        if (s[i - 1] == 'W') dp[i].first++;
        else dp[i].second++;
    }

    dfs(1);

    cout << resp << endl;

    resp = 0;
    for (int i=0; i <= n; i++) {
        vis[i] = 0;
        adj[i].clear();
        dp[i].first = 0;
        dp[i].second = 0;
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
