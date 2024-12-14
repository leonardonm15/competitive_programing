#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define tii tuple<int, int, int>

const int INF = 1e18;

void solve () {
    int n; cin >> n;

    vector<tii> arr(n);
    vector<vector<int>> vis(2, vector<int>(n));

    for (int i = 0; i < n; i++) {
        auto& [a, b, c] = arr[i];
        cin >> a;
        c = i;
    }

    for (int i = 0; i < n; i++) {
        auto& [a, b, c] = arr[i];
        cin >> b;
        c = i;
    }

    int soma = 0;
    for (auto [a, b, c]: arr) {
        if (a > b) {
            vis[0][c]++;
            soma += a;
        } else {
            vis[1][c]++;
            soma += b;
        }
    }

    int resp = -INF;
    for (int i = 0; i < n; i++) {
        auto [a, b, c] = arr[i];
        if (vis[0][c]) resp = max(resp, soma + b);
        else resp = max(resp, soma + a);
    }

    cout << resp << endl;
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
