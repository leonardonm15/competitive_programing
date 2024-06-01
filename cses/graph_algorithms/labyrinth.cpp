#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int n, m;
const int N = 1e3 + 5;
const int INF = 1e9 + 5;
vector<string> adj;
pair<int, int> moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> dist(N, vector<int>(N, INF));
map<pair<int, int>, char> direction;

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && adj[i][j] != '#');
}

void bfs(int i, int j) {
    dist[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [x, y]: moves) {
            if (valid(i + x, j + y) && (dist[i][j] + 1 < dist[i + x][j + y])) {
                dist[i + x][j + y] = dist[i][j] + 1;
                q.push({i + x, j + y});
            }
        }
    }
}

vector<char> resp;
void find_path(int i, int j) {
    bool flag = false;
    for (auto [x, y]: moves) {
        if (valid(i + x, j + y) && (dist[i + x][j + y] == dist[i][j] - 1) && !flag) {
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 'A') {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] != INF && adj[i][j] == 'B') {
                find_path(i, j);
            }
        }
    }

    if (resp.size()) {
        cout << "YES" << endl;
        reverse(resp.begin(), resp.end());
        cout << resp.size() << endl;
        for (auto c: resp) cout << c;
        cout << endl;
    } else cout << "NO" << endl;
}

signed main() {
    // ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
