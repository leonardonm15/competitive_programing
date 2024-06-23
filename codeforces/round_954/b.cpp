#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 100 + 5;
pair<int, int> moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int adj[N][N];

bool valid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = -1;
            for (auto [x, y]: moves) {
                if (valid(i + x, j + y, n, m)) k = max(k, adj[i + x][j + y]);
            }

            if (adj[i][j] > k) adj[i][j] = k;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
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
