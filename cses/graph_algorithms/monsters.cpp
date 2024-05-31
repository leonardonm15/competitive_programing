#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<string> adj;
pair<int, int> moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve () {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        adj.push_back(s);
    }

    for (int i=0; i < n; i++) {
    }
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
