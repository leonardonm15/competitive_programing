#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m, k; cin >> n >> m >> k; // k é o priemiro;
    vector<int> resp;

    // caras >= k
    // caras <= m 

    if (k > m) {
        // for (int i = k; i <= n; i++) resp.push_back(i);
        for (int i = n; i >= k; i--) resp.push_back(i);
        for (int i = m + 1; i < k; i++) resp.push_back(i);
        for (int i = 1; i <= m; i++) resp.push_back(i);
    } else {
        for (int i = n; i > m; i--) resp.push_back(i);
        for (int i = k; i <= m; i++) resp.push_back(i);
        for (int i = 1; i < k; i++) resp.push_back(i);
        //for (int i = k - 1; i >= 1; i--) resp.push_back(i);
    }

    for (auto c: resp) cout << c << " ";
    cout << endl;
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
