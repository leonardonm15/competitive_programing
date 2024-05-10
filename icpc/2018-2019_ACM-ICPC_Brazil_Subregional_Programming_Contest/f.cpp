#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define int long long

struct node {
    int l, r, p, w;
};

const int N = 1e3 + 5;
int n;
vector<int> adj[N];
vector<node> nodes;
vector<vector<int>> dp(N, vector<int> (1 << 10, -1));

int calc(int u, int pcs) {
    if (dp[u][pcs] != -1) return dp[u][pcs];
    if (!adj[u].size() && pcs == (1 << nodes[u].p)) return dp[u][pcs] = nodes[u].w;
    else if (!adj[u].size() && pcs != (1 << nodes[u].p)) return dp[u][pcs];

    for (auto v : adj[u]) {
        int a = calc(v, pcs);
        int b = calc(v, pcs ^ (1 << nodes[u].p));
        if (a == - 1 && b == -1) dp[u][pcs] = -1;
        else dp[u][pcs] = max(dp[u][pcs], max(a, b) + nodes[u].w);
    }

    return dp[u][pcs];
}

void solve () {
	cin >> n;
    for (int i=0; i < n; i++) {
        int k; cin >> k;
        for (int j=0; j < k; j++) {
            int c, f, w; cin >> c >> f >> w;
            node v;
            v.l = c;
            v.r = f;
            v.p = i;
            v.w = w;
            nodes.push_back(v);
        }
    }

    vector<int> top(nodes.size());
    for (int i=0; i < (int)nodes.size(); i++) {
        for (int j=0; j < (int)nodes.size(); j++) {
            node &a = nodes[i];
            node &b = nodes[j];
            if (a.r <= b.l) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < (int)nodes.size(); i++) calc(i, (1 << n) - 1);

    int resp = -1;
    for (int i=0; i < (int)nodes.size(); i++) {
        resp = max(resp, dp[i][(1 << n) - 1]);
    }

    cout << resp << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}

