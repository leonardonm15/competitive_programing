#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int N = 1e3+3;
const ii dir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;
char mat[N][N];
int vis[N][N];

bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    bool ok = 1;
    for (auto [dx, dy]: dir) {
        int xx = x + dx, yy = y + dy;
        if (valid(xx, yy) && mat[xx][yy] == 'T') ok = 0;
    }
    if (!ok) return;

    for (auto [dx, dy]: dir) {
        int xx = x + dx, yy = y + dy;
        if (valid(xx, yy) && mat[xx][yy] != '#' && !vis[xx][yy]) {
            dfs(xx, yy);
        }
    }
}


void solve() {
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            vis[i][j] = 0;
            if (mat[i][j] == 'S') sx = i, sy = j;
        }
    }

    //cout << << " " << sy << endl;
    dfs(sx, sy);

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout << mat[i][j] << " ";
            if ('1' <= mat[i][j] && mat[i][j] <= '9' && vis[i][j]) {
                res += mat[i][j] - '0';
            }
        } 
        //cout << endl;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n >> m)
    solve();
}
