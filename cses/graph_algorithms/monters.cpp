#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
int n, m;
const int N = 1e3 + 5;
const int INF = 1e9 + 5;
vector<string> adj;
pair<int, int> moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> dista(N, vector<int>(N, INF));
vector<vector<int>> distb(N, vector<int>(N, INF));
map<pair<int, int>, char> direction;
pair<int, int> saida = {-1, -1};
 
bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && adj[i][j] != '#');
}
 
bool is_edgy(int i, int j) {
    return ((i == 0 || i == n - 1) || (j == 0 || j == m - 1));
}
 
void abfs(int i, int j) {
    dista[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (q.size()) {
        auto [i, j] = q.front();
        if (is_edgy(i, j) && dista[i][j] < distb[i][j]) saida = {i, j};
        q.pop();
        for (auto [x, y]: moves) {
            if (valid(i + x, j + y) && (dista[i][j] + 1 < dista[i + x][j + y])) {
                dista[i + x][j + y] = dista[i][j] + 1;
                q.push({i + x, j + y});
            }
        }
    }
}
 
void bbfs(int i, int j) {
    distb[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (q.size()) {
        auto [i, j] = q.front();
        if (adj[i][j] == 'M') distb[i][j] = 0;
        q.pop();
        for (auto [x, y]: moves) {
            if (valid(i + x, j + y) && (distb[i][j] + 1 < distb[i + x][j + y])) {
                distb[i + x][j + y] = distb[i][j] + 1;
                q.push({i + x, j + y});
            }
        }
    }
}
 
vector<char> resp;
void find_path(int i, int j) {
    bool flag = false;
    for (auto [x, y]: moves) {
        if (valid(i + x, j + y) && (dista[i + x][j + y] == dista[i][j] - 1) && !flag) {
            flag = true;
            resp.push_back(direction[{x * -1, y * -1}]);
            find_path(i + x, j + y);
        }
    }
}
 
void solve () {
    cin >> n >> m;
    direction[{1, 0}] = 'D';
    direction[{-1, 0}] = 'U';
    direction[{0, 1}] = 'R';
    direction[{0, -1}] = 'L';
 
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        adj.push_back(s);
    }
 
    bool para = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 'M' && !para) {
                bbfs(i, j);
                para = true;
            }
        }
    }

    /* for (int i=0; i < n; i++) { */
    /*     for (int j=0; j < m; j++) { */
    /*         if (distb[i][j] != INF) cout << distb[i][j] << " "; */
    /*         else cout << "# "; */
    /*     } */
    /*     cout << endl; */
    /* } */
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 'A') {
                abfs(i, j);
            }
        }
    }
 
    pair<int, int> dm = {-1, -1};
    if (saida != dm) {
        find_path(saida.first, saida.second);
        reverse(resp.begin(), resp.end());
        cout << "YES" << endl;
        cout << resp.size() << endl;
        for (auto c: resp) cout << c;
        cout << endl;
    } else cout << "NO" << endl;
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
