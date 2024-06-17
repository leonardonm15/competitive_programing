#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e6 + 5;
const int M = 1e3 + 5;

vector<string> mat;
vector<vector<int>> cor;
int sz[N];
int n, m;

pair<int, int> moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == '#');
}

bool valid2(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == '1');
}

void dfs(int i, int j, int c) {
    cor[i][j] = c;
    mat[i][j] = '1';
    sz[c]++;
    for (auto [x, y]: moves) {
        if (valid(i + x, j + y)) dfs(i + x, j + y, c);
    }
}

void add_cor(int i, int j, map<int, int>& mp, int& k) {
    if (!mp[cor[i][j]]) {
        mp[cor[i][j]]++;
        k += sz[cor[i][j]];
    }
}

void solve () {
    cin >> n >> m;
    vector<vector<int>> e(n, vector<int>(m, -1));
    cor = e;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mat.push_back(s);
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '#') {
                dfs(i, j, c++);
            }
        }
    }

    int resp = max(n, m);
    for (int i = 0; i < n; i++) {
        map<int, int> mp;
        int k = 0;
        int menos = 0;
        for (int j = 0; j < m; j++) {
            if (valid2(i + 1, j)) add_cor(i + 1, j, mp, k);
            if (valid2(i - 1, j)) add_cor(i - 1, j, mp, k);
            if (valid2(i, j)) {
                menos++;
                add_cor(i, j, mp, k);
            }
        }

        resp = max(resp, k + (m - menos));
    }

    for (int j = 0; j < m; j++) {
        map<int, int> mp;
        int k = 0;
        int menos = 0;
        for (int i = 0; i < n; i++) {
            if (valid2(i, j + 1)) add_cor(i, j + 1, mp, k);
            if (valid2(i, j - 1)) add_cor(i, j - 1, mp, k);
            if (valid2(i, j)) {
                menos++;
                add_cor(i, j, mp, k);
            }
        }

        resp = max(resp, k + (n - menos));
    }

    cout << resp << endl;

    for (int i = 0;  i <= c; i++) sz[i] = 0;
    mat.clear();
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
