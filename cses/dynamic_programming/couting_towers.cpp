#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int N = 1e6 + 5;
const int L = 2;
const int MOD = 1e9 + 7;

int dp[N][L][L][L];

int calc(int n, int l1, int l2, int m) {
    /* cout << "n -> " << n << endl; */
    if (n < 1) return 0;
    if (dp[n][l1][l2][m] != -1) return dp[n][l1][l2][m];

    int k = 0;
    if (!l1 && !l2 && !m) {
        k += calc(n - 1, 0, 0, 0);
        k %= MOD;
        k += calc(n - 1, 1, 1, 0);
        k %= MOD;
    }

    if (!l1 && !l2 && m) {
        k += calc(n - 1, 0, 1, 1); 
        k %= MOD;
        k += calc(n - 1, 1, 0, 1);
        k %= MOD;
        k += calc(n - 1, 1, 1, 1);
        k %= MOD;
        k += calc(n - 1, 0, 0, 1);
        k %= MOD;
    }

    if (!l1 && l2 && !m) {
    }

    if (!l1 && l2 && m) {
        k += calc(n - 1, 0, 0, 1);
        k %= MOD;
        k += calc(n - 1, 1, 1, 1);
        k %= MOD;
        k += calc(n - 1, 0, 1, 1);
        k %= MOD;
        k += calc(n - 1, 1, 0, 1);
        k %= MOD;
    }

    if (l1 && !l2 && !m) {
    }

    if (l1 && !l2 && m) {
        k += calc(n - 1, 0, 0, 1);
        k %= MOD;
        k += calc(n - 1, 1, 1, 1);
        k %= MOD;
        k += calc(n - 1, 0, 1, 1);
        k %= MOD;
        k += calc(n - 1, 1, 0, 1);
        k %= MOD;
    }

    if (l1 && l2 && !m) {
        k += calc(n - 1, 0, 0, 1); // so meio
        k %= MOD;
        k += calc(n - 1, 1, 1, 0); // tudo baixo
        k %= MOD;
        k += calc(n - 1, 1, 1, 1); // tudo baixo e meio
        k %= MOD;
        k += calc(n - 1, 0, 0, 0); // nada
        k %= MOD;
        k += calc(n - 1, 1, 0, 1); // esquerda meio
        k %= MOD;
        k += calc(n - 1, 0, 1, 1); // direita meio
        k %= MOD;
    }

    if (l1 && l2 && m) {
        k += calc(n - 1, 0, 0, 1); // so meio
        k %= MOD;
        k += calc(n - 1, 1, 1, 0); // tudo baixo
        k %= MOD;
        k += calc(n - 1, 1, 1, 1); // tudo baixo e meio
        k %= MOD;
        k += calc(n - 1, 0, 0, 0); // nada
        k %= MOD;
        k += calc(n - 1, 1, 0, 1); // esquerda meio
        k %= MOD;
        k += calc(n - 1, 0, 1, 1); // direita meio
        k %= MOD;
    }

    return dp[n][l1][l2][m] = k;
}

void setup() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            for (int k = 0; k < L; k++) {
                for (int l = 0; l < L; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    dp[1][1][1][0] = 1ll;
    dp[1][1][1][1] = 1ll;
    calc(1e6 + 1, 1, 1, 0);
}

void solve () {
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        cout << dp[n + 1][1][1][0] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        setup();
        solve();
    }
    return 0;
}
