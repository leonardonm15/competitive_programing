#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 10 + 5;
const int M = 1e3 + 5;



int dp[M][N];
int calc(int i, int j) {
    if (i == 0 && j == 0) return 1;
    if (!valid(i, j)) return 0;

}

void solve () {
    int n, int m; cin >> n >> m;

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
