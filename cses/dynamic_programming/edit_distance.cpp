#include <bits/stdc++.h>

using namespace std;
 
#define int long long
#define endl '\n'
 
const int N = 5000 + 5;
const int MX = 1e9;
int dp[N][N];
string n, m;
 
int calc(int i, int j) {
    if (dp[i][j] != MX) return dp[i][j];
    if (i == 0 || j == 0) return max(i, j);
    if (n[i - 1] == m[j - 1]) dp[i][j] = min(dp[i][j], calc(i - 1, j - 1));
    dp[i][j] = min({
            dp[i][j], 
            calc(i - 1, j) + 1, 
            calc(i, j - 1) + 1, 
            calc(i - 1, j - 1) + 1,
            });
    return dp[i][j];
}
 
void solve() {
    cin >> n >> m;
 
    for (int i = 0; i <= 5000; i++) {
        for (int j = 0; j <= 5000; j++) dp[i][j] = MX;
    }

    dp[0][0] = 0;
 
    cout << calc(n.size(), m.size()) << endl;
}
 
signed main() {
    solve();
} 
