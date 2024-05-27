#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e4 + 5;

int dp[N][N];
int arr[N];

void calc(int n) {
    for (int i = 1; i < n; i++) dp[i - 1][i] = abs(arr[i - 1] - arr[i]);

    for (int k=2; k < n; k++) {
        for (int i = 1; i < n; i++) {
            if (i < k) continue;
            dp[i - k][i] = min({dp[i - k][i - 1], dp[i - k + 1][i], abs(arr[i - k] - arr[i])});
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    calc(n);

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << dp[l - 1][r - 1] << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
