#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m, L; cin >> n >> m >> L; // huerdles, pwup, end

    vector<pair<int, int>> hurdles(n);

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        hurdles[i] = {l, r};
    }

    vector<pair<int, int>> mxp(m);

    int x = 0;
    for (int i = 0; i < m; i++) {
        int p, v; cin >> p >> v;
        x = max(x, v);
        mxp[i] = {p, x};
    }

    int changes = 0;
    int mx_atual = 1;
    int atual = 1;
    for (auto [l, r]: hurdles) {
        int down = 0;
        int up = mxp.size() - 1;
        int ans = 0;

        while (down <= up) {
            int mid = (down + up) >> 1;
            /* cout << "-----------------" << endl; */
            /* cout << "down -> " << down << endl; */
            /* cout << "up -> " << up << endl; */
            /* cout << "Mid -> " << mid << endl; */

            if (mxp[mid].first <= l) {
                ans = mxp[mid].second;
                down = mid + 1;
            } else {
                up = mid - 1;
            }
        }


        mx_atual = ans;
        cout << "mx_atual -> " << mx_atual << endl;
        
        if (l - 1 + atual <= r) {
            if (l - 1 + mx_atual <= r) {
                cout << -1 << endl;
                return;
            } else {
                changes++;
                atual = mx_atual;
            }
        } else {
            continue;
        }
    }

    cout << changes << endl;

}

signed main() {
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
