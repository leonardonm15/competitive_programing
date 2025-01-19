#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define matr vector<vector<int>>

void solve () {
    int n, m; cin >> n >> m;
    string path; cin >> path;
    path.push_back('D');

    matr mat(n, vector<int>(m));
    vector<int> linha(n), coluna(m);

    int mult = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            linha[i] += mat[i][j];
            coluna[j] += mat[i][j];

            if (mat[i][j] != 0) mult *= abs(mat[i][j]);
        }
    }

    pair<int, int> now = {0, 0};

    for (auto direction: path) {
        int l = linha[now.first];
        int c = coluna[now.second];
        int i = now.first;
        int j = now.second;

        if (direction == 'D') {
            mat[i][j] = -linha[i];
            coluna[j] -= linha[i];
            linha[i] = 0;
            now.first += 1;
        }

        if (direction == 'R') {
            mat[i][j] = -coluna[j];
            linha[i] -= coluna[j];
            coluna[j] = 0;
            now.second += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
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
