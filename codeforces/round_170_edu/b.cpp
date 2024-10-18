#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int MOD = 1e9 + 7;

int bpow(int a) {
    int b = 1;
    int k = 2;
    while (a) {
        if (a&1) {
            b *= k;
            b %= MOD;
        }

        k *= k;
        k %= MOD;
        a >>= 1;
    }
    return b;
}

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;

    for (auto [u, v]: arr) {
        if (v == u + 1 || v == 0) cout << 1 << endl;
        else cout << bpow(v) << endl;
    }
    return;

    vector<vector<int>> c(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int k = 1; k < i; k++) {
            cout << "i -> " << i << endl;
            cout << "k -> " << k << endl;
            if (i > 0) c[i][k] = c[i][k - 1] + c[i - 1][k - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

}

signed main() {
    solve();
}
 
