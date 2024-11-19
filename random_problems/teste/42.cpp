#include <string>
#include <vector>

using std::string;
using std::vector;
using std::pair;

#define mat vector<vector<vector<pair<int, int>>>>


void dfs(int i, int j, vector<vector<int>>& resp, vector<vector<int>>& vis, mat& adj) {
    vis[i][j]++;
    for (auto [vi, vj]: adj[i][j]) {
        if (!vis[vi][vj]) dfs(vi, vj, resp, vis, adj);
    }

    resp.push_back({j, i});
}

vector<vector<int>> find_snake_on_grid(const vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    mat adj;
    adj.resize(n, vector<vector<pair<int, int>>>(m));
    vector<vector<int>> vis(n, vector<int>(m));

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

    dfs(x, y, resp, vis, adj);

    reverse(resp.begin(), resp.end());
    return resp;
}
