#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const double EPS = 1e-9

void solve () {
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(k + 1);
    vector<int> b(k + 1);
    vector<double> vels;

    for (int i=0; i < k; i++) cin >> a[i + 1];
    for (int i=0; i < k; i++) cin >> b[i + 1];

    for (int i=1; i <= k; i++) {
        /* vels.push_back((a[i] - a[i - 1]) / b[i]); */
        vels.push_back(static_cast<double>(a[i] - a[i - 1]) / (b[i] - b[i - 1]));
    }

    /* cout << "vels -> "; */
    /* for (auto cara: vels) cout << cara << " "; */
    /* cout << endl; */

    vector<int> resp;
    while(q--) {
        int d; cin >> d;
        int l = 0;
        int r = k;
        int idx = 0;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] > d) {
                r = mid - 1;
            } else {
                idx = mid;
                l = mid + 1;
            }
            /* cout << "mid -> " << mid << endl; */
        }

        if (a[idx] == d) resp.push_back(b[idx]);
        else if (idx == 0) {
            int dist = d - a[idx];
            int tm = floor(dist / vels[idx] + EPS);
            resp.push_back(tm);
        }
        else {
            int dist = d - a[idx];
            int tm = floor((dist / vels[idx])+EPS);
            /* cout << "dist -> " << dist << endl; */
            /* cout << "vels[idx] -> " << vels[idx] << endl; */
            /* cout << "tm -> " << tm << endl; */
            resp.push_back(b[idx] + tm);
        }
    }

    for (auto cara: resp) cout << cara << " ";
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