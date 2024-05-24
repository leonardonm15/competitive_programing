#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
vector<vector<int>> cav(30, vector<int>(30, 0));
vector<vector<int>> add(30, vector<int>(30, 0));

void solve () {
    int n, q; cin >> n >> q;
    for (int i=0; i < q; i++) {
        cin >> a >> b; cin >> a >> b;
        cav[a][b]++;
    }

    vector<pair<int, int>> moves = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

    bool conflict = false;

    for (int i=1; i <= n; i++) {
        for (int j=1; j <= n; j++) {
            if (cav[i][j]) {
                for (auto [x, y]: moves) {
                    if ((i + x >= 1 && i + x <= n) && (j + y >= 1 && j + y <= n) && cav[i + x][j + y]) {
                        add[i][j]++;
                        conflict = true;
                    }
                }
            }
        }
    } 

    tuple<int, int, int> mx = {-1, -1, -1};
    while (conflict) {
        for (int i=1; i <=n; i++) {
            for (int j=1; j <= n; j++) {
                if (cav[i][j]) {
                    auto [w, x, y] = mx;
                    if (cav[i][
                }
            }
        }
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
