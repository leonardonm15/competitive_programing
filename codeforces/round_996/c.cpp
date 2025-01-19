#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define matr vector<vector<int>>

/* bool check(matr& mat, vector<int>& linhas, vector<int>& colunas, int mid, string& path, int n) { */
/*     pair<int, int> now = {0, 0}; */
/*     pair<int, int> destination = {n - 1, n - 1}; */

/*     vector<int> vals; */
/*     for (auto step: path) { */
/*         int current = 0; */
/*         now.first */
/*     } */
/* } */

void solve () {
    int n, m; cin >> n >> m;
    string path; cin >> path;
    path.push_back('s');

    matr mat(n, vector<int>(m));
    vector<int> linha(n), coluna(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            linha[i] += mat[i][j];
            coluna[j] += mat[i][j];
        }
    }

    cout << "----------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cout << (linha[i] + coluna[j]) - mat[i][j] << " ";
        }
        cout << endl;
    }
    return;

    cout << "linha -> ";
    for (auto l: linha) cout << l << " ";
    cout << endl;

    cout << "coluna -> ";
    for (auto c: coluna) cout << c << " ";
    cout << endl;
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
