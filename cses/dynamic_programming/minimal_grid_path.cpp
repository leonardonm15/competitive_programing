#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define pii pair<int, int>

const int N = 3000 + 5;
int n;
string adj[N];
vector<pii> aberracao[N * 2 - 1][26];
int vis[N][N];

bool can_reach(int i, int j) {
    return (vis[i][j] ? true : false);
}

bool valid(int i, int j) {
    if (i < 0 || j < 0) return false;
    if (i >= n || j >= n) return false;
    else return can_reach(i, j);
}

void build_aberracao() {
    int diagonalzinha = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char cara = adj[i][j];
            aberracao[diagonalzinha + j][cara - 'A'].push_back({i, j});
        }
        diagonalzinha++;
    }
}

void solve () {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> adj[i];
    }

    build_aberracao();
    vis[0][0] = 1;
    string resp(2 * n - 1, 'Z' + 1);
    resp[0] = adj[0][0];

    for (int i = 1; i < 2 * n - 1; i++) {
        for (int j = 0; j < 26; j++) {
            bool skip = false;
            for (auto [a, b]: aberracao[i][j]) {
                if ((valid(a - 1, b) || valid(a, b - 1))) {
                    resp[i] = min(resp[i], adj[a][b]);
                    vis[a][b]++;
                    skip = true;
                }
            }
            if (skip) break;
        }
    }


    cout << resp << endl;
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
