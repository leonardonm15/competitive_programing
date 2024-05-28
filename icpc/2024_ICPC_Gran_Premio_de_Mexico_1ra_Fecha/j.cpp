#include <bits/stdc++.h>

// #define int long long
#define endl '\n'
using namespace std;

string s;
const int N = 500 + 5;

int dp[N][N][N]; // l r quantidade de coringas usados
int resp = 1e9 + 5;

void calc(int n) { // string size, coringas
    for (int i=0; i < n; i++) dp[i][i][0] = 1;

    for (int i=1; i < n; i++) {
        (s[i] == s[i - 1] ? dp[i - 1][i][0] = 2 : (dp[i - 1][i][1] = 2, dp[i - 1][i][0] = 1));
    }

    for (int k = 2; k < n; k++) {
        for (int i=2; i < n; i++) {
            for (int c = 0; c <= n; c++) {
                if (i < k) continue;
                int range = (k + 1);
                int r = i;
                int l = i - k;
                dp[l][r][c] = max({dp[l + 1][r][c], dp[l][r - 1][c], dp[l + 1][r - 1][c] + (s[l] == s[r] ? 2 : 0)});
                if (c > 0 && s[l] != s[r]) dp[l][r][c] = max(dp[l][r][c], dp[l + 1][r - 1][c - 1] + 2);
            }
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    cin >> s;
    calc(n);

    for (int c = 0; c <= n; c++) {
        if (dp[0][n - 1][c] >= k) {
            cout << c << endl;
            return;
        }
    }
}

 signed main() {
     cin.tie(0)->sync_with_stdio(0);
     solve();
     return 0;
 }
