#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<vector<char>> arr(10, vector<char>(10, '.'));
/* vector<vector<bool>> vis(10, vector<bool>(10)); */

char cs;
int c = 0;

void dfs(int i, int j, char stage, int ip, int jp) {
    /* cout << "i j -> " << i << " - " << j << endl; */
    cout << "c - > " << c << endl;
    if (stage == cs) {
        c++;
    } 
    if (stage == 'B') {
        if (arr[i - 1][j] == stage && i - 1 != ip) dfs(i - 1, j, stage, i, j);
        if (arr[i + 1][j] == stage && i + 1 != ip) dfs(i + 1, j, stage, i, j);
    } else if (stage == 'A') {
        if (arr[i][j - 1] == stage && j - 1 != jp) dfs(i, j + 1, stage, i, j);
        if (arr[i][j + 1] == stage && j + 1 != jp) dfs(i, j - 1, stage, i, j);
    } else return;
}

void solve () {
    int n = 8;
    for (int i=1; i <= 8; i++) {
        for (int j=1; j <= 8; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= n; j++) {
            if ((arr[i][j] == 'R' || arr[i][j] == 'B')) {
                cs = arr[i][j];
                dfs(i, j, arr[i][j], -1, -1);
                if (c == 8) {
                    cout << arr[i][j] << endl;
                    return;
                } else c = 0;
            }
        }
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
