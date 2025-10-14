#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N = 1e5 + 5;
const int B = 500; // tamanho barco atual

int g, n;

int dp[N][B];
int arr[N];
int pref[N];

int calc(int i, int tb) {
    if (dp[i][tb] != -1) return dp[i][tb];
    if (i == n) return 0;

    int custo = pref[i + tb] - pref[i];
    if (i + tb <= n) dp[i][tb] = max(dp[i][tb], calc(i + tb, tb + 1) - custo + g);
    dp[i][tb] = max(
            dp[i][tb],
            calc(i + 1, tb)
           );

    return dp[i][tb];
}

void solve() {
    cin >> n >> g;

    int soma = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        soma += arr[i];
        pref[i + 1] = soma;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < B; j++) {
            dp[i][j] = -1;
        }
    }

    cout << calc(0, 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}
