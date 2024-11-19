#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<vector<vector<pair<int, int>>>> adj;

vector<vector<int>> vis;

void dfs(int i, int j, vector<vector<int>>& resp) {
    vis[i][j]++;
    for (auto [vi, vj]: adj[i][j]) {
        if (!vis[vi][vj]) dfs(vi, vj, resp);
    }

    resp.push_back({j, i});

}

void solve () {
    vector<string> grid = {
        "v<<",
        "vh<",
        ">>^"
    };

    int n = grid.size();
    int m = grid[0].size();

    adj.resize(n, vector<vector<pair<int, int>>>(m));
    vis.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char k = grid[i][j];
            pair<int, int> indo_para;
            if (k == 'h') continue;
            if (k == 'v') indo_para = {i + 1, j};
            if (k == '<') indo_para = {i, j - 1};
            if (k == '>') indo_para = {i, j + 1};
            if (k == '^') indo_para = {i - 1, j};

            /* cout << indo_para.first << " " << indo_para.second << endl; */
            adj[i][j].push_back(indo_para);
            adj[indo_para.first][indo_para.second].push_back({i, j});
        }
    }

    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < m; j++) { */
    /*         cout << "------------" << endl; */
    /*         cout << i << " " << j << " adj -> "; */
    /*         for (auto [a, b]: adj[i][j]) { */
    /*             cout << a << " " << b << " ----- "; */
    /*         } */
    /*         cout << endl; */
    /*     } */
    /* } */

    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'h') {
                 x = i;
                 y = j;
            }
        }
    }

    vis[x][y]++;

    vector<vector<int>> resp;

    dfs(x, y, resp);

    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < m; j++) { */
    /*         cout << vis[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    reverse(resp.begin(), resp.end());
    for (auto vec: resp) {
        cout << vec[0] << " " << vec[1] << endl;
    }

}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
