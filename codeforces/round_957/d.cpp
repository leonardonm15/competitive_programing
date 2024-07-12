#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 50;
const int INF = 1e18;

int ta[N]; // tempo na agua 

void solve () {
    int n, m, k; cin >> n >> m >> k;
    string s;
    string r; cin >> r;
    s += "L";
    s += r;
    s += "L";

    for (int i = 1; i <= n + 15; i++) ta[i] = INF;
    
    for (int i = 0; i < s.size(); i++) {
        /* cout << s[i]; */
        if (ta[i] == INF) continue;

        if (s[i] == 'L') {
            for (int k = 1; k <= m; k++) {
                ta[i + k] = min(ta[i + k], ta[i]);
            }
        }

        if (s[i] == 'W' && s[i + 1] != 'C') {
            ta[i + 1] = min(ta[i] + 1, ta[i + 1]);
        }
    }
    /* cout << endl; */

    /* cout << "ta -> "; */
    /* for (int i = 0; i <= n + 1; i++) cout << ta[i] << " "; */
    /* cout << endl; */

    cout << (ta[n + 1] <= k ? "YES" : "NO") << endl;
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
