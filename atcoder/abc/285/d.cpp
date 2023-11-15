#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 1e6;
vector<int> vis(maxn);
vector<int> adj[maxn];
bool flag = false;
map<string, int> m;

void dfs(int a, int b) {
    vis[a]++;
    for (auto cara: adj[a]) {
        if (cara == b) continue;
        if (vis[cara]) {
            /* cout << "pai -> " << a << endl; */
            flag = true;
            return;
        } else dfs(cara, a);
    }
}

void solve () {
    int n; cin >> n;
    int counter = 1;
    for (int i=0; i < n; i++) {
        string s, k; cin >> s >> k;
        if (!m[s]) {
            m[s] = counter;
            counter++;
        }
        if (!m[k]) {
            m[k] = counter;
            counter++;
        }
        adj[m[s]].push_back(m[k]);
        adj[m[k]].push_back(m[s]);
    }
    for (int i=0; i < maxn; i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }
    if (flag) cout << "No" << endl;
    else cout << "Yes" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

