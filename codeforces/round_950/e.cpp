#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define mat vector<vector<tuple<int, int, int>>>

int n, m;

void organize(mat& a) {
    int row = 0;
    for (int i = 0; i < n; i++) {
        vector<tuple<int, int, int>> c;
        for (int j = 0; j < m; j++) {
            auto [val, r, col] = a[i][j];
            if (val == 1) {
                sort(a[i].begin(), a[i].end());
                row = i;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        vector<tuple<int, int, int>> c(m);
        bool flag = false;
        for (int j = 0; j < m; j++) {
            auto [val, r, col] = a[row][j];
            if (val == 1) flag = true;
            c[j] = a[i][col];
        }
        if (!flag) swap(a[i], c);
    }

    cout << "a ------------------- a" << endl;
    for (auto c: a) {
        for (auto [cara, x, y]: c) cout << cara << " ";
        cout << endl;
    }
}

void solve () {
    cin >> n >> m;
    mat a(n);
    mat b(n);

    for (int i = 0; i < n; i++) {
        vector<tuple<int, int, int>> c;
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            c.push_back({num, i, j});
        }
        a[i] = c;
    }

    for (int i = 0; i < n; i++) {
        vector<tuple<int, int, int>> c;
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            c.push_back({num, i, j});
        }
        b[i] = c;
    }

    organize(a);
    organize(b);

    /* bool win = true; */
    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < m; j++) { */
    /*         auto [n1, i1, j1] = a[i][j]; */
    /*         auto [n2, i2, j2] = b[i][j]; */
    /*         if (n1 != n2) win = false; */
    /*     } */
    /* } */


    /* cout << "b ------------------- b" << endl; */
    /* for (auto c: b) { */
    /*     for (auto [cara, x, y]: c) cout << cara << " "; */
    /*     cout << endl; */
    /* } */

    /* cout << (win ? "YES" : "NO") << endl; */
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
