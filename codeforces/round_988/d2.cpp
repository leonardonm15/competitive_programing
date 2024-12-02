#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m, L; cin >> n >> m >> L;

    vector<pair<int, int>> hurdles(n);

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        hurdles[i] = {l, r};
    }

    vector<pair<int, int>> pwup(m);

    for (int i = 0; i < m; i++) {
        int p, v; cin >> p >> v;

        pwup[i] = {v, p};
    }

    int j = 0;
    int jump = 1;
    int changes = 0;
    priority_queue<int> pq;
    for (auto [l, r]: hurdles) {
        while (j < m && pwup[j].second < l) {
            pq.push(pwup[j++].first);
        }
        
        while (pq.size() && l - 1 + jump <= r) {
            jump += pq.top();
            changes++;
            pq.pop();
        }

        if (l - 1 + jump <= r) {
            cout << -1 << endl;
            return;
        }
    }

    cout << changes << endl;
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
