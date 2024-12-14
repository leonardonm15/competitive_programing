#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int INF = 1e18;

void solve () {
    int n; cin >> n;
    /* vector<vector<int>> arr(2, vector<int>(n)); */

    // i, j, cima ou lado
    
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }
    
    vector<pair<int, int>> ps(n + 1); // prefixo em cima e sufixo em baixo

    sort(arr.begin(), arr.end());

    for (int i = 1; i <= n; i++) {
        ps[i].first = ps[i - 1].first + arr[i - 1].first;
    }

    for (int i = n - 1; i >= 0; i--) {
        ps[i].second = ps[i + 1].second + arr[i].second;
    }

    cout << "arrf -> ";
    for (auto [f, s]: arr) cout << f << " ";
    cout << endl;

    cout << "arrs -> ";
    for (auto [f, s]: arr) cout << s << " ";
    cout << endl;

    cout << "psf -> ";
    for (auto [f, s]: ps) cout << f << " ";
    cout << endl;

    cout << "pfs -> ";
    for (auto [f, s]: ps) cout << s << " ";
    cout << endl;

    int r1 = -INF;
    for (int i = 1; i <= n; i++) {
        r1 = max(r1, ps[i].first + ps[i - 1].second);
    }

    cout << "r1 -> " << r1 << endl;

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
