#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
/* #define int long long */

struct node {
    int l, r, p, w;
    node() {
        w = -1;
        l = -1;
        r = -1;
        p = -1;
    }
};

const int N = 1e3 + 5;
const int S = 86401;

int n;
vector<int> adj[N];
vector<vector<node>> nodes(S);
vector<vector<int>> dp(S, vector<int> (1 << 10, -1));

void solve () {
	cin >> n;
    for (int i=0; i < n; i++) {
        int k; cin >> k;
        for (int j=0; j < k; j++) {
            int c, f, w; cin >> c >> f >> w;
            node v = node();
            v.l = c;
            v.r = f;
            v.p = i;
            v.w = w;
            nodes[c].push_back(v);
        }
    }

    dp[0][0] = 0;
    for (int i=1; i < S; i++) {
        for (int msk=0; msk <= (1 << 10) - 1; msk++) {
            dp[i][msk] = max(dp[i - 1][msk], dp[i][msk]);
            if (dp[i][msk] == -1) continue;
            for (auto nd: nodes[i]) {
                node k = nd;
                dp[k.r][msk | (1 << k.p)] = max(dp[i][msk] + k.w, dp[k.r][msk | (1 << k.p)]);
            }
        }
    }

    int resp = -1;
    for (int i=1; i < S; i++) {
        resp = max(resp, dp[i][(1 << n) - 1]);
    }

    cout << resp << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}

