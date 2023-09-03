#include <bits/stdc++.h>

using namespace std;
//#define int long long

void dfs (int i, int j, vector<vector<char>> &arr) {
    if (arr[i][j] != '.') return;
    if (arr[i + 1][j] == '.') {
        arr[i + 1][j] = 'o';
        dfs(i + 1, j, arr);
    } else {
        if (arr[i][j-1] == '.') {
            arr[i][j - 1] = 'o';
            dfs(i, j - 1, arr);
        }
        if (arr[i][j + 1] == '.') {
            arr[i][j + 1] = 'o';
            dfs(i, j + 1, arr);
        }
    }
}

void solve () {
    int n, m; cin >> n >> m;
    vector<vector<char>> arr(n + 2, vector<char> (m + 2, '#'));
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= m; j++) {
            char a; cin >> a;
            arr[i][j] = a;
        }
    }
    cout << endl;
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= m; j++) {
            if (arr[i][j] == 'o') {
                dfs(i, j, arr);
                break;
            }
        }
    }
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= m; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }


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
