#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = (1e3 * 1e3) + 5;
const int K = 1e5 + 5;
const int INF = 1e18;

vector<vector<int>> dp(N, vector<int>(N, INF));

void solve () {
    int n, k; cin >> n >> k;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<int> old(N, INF); // preço fica no valor da dp;
    vector<int> now(N, INF); // 

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
