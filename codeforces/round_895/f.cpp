#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 1e5 + 5;


void solve () {
    vector<int> adj[maxn];
    vector<int> p(maxn);
    int n;
    vector<pair<int, int>> top(n, pair<int, int>{0, 0});
    for (int i=1;i <= n; i++) {
        int num; cin >> num;
        adj[i].push_back(num);
        top[num].first++;
        top[num].second = num;
    }
    sort(top.first(), top.end());
    // recebe no adj, sorta o topological, ve os caras que são solitarios;
    for (i=0; i <= n; i++) {
        if (top[i].second == 0) continue;
        if (!top[i].first&1) {
            
        }
    }
    for (int i=1; i < n; i++) {
        int num; cin >> num;
        p[i] = num;
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
