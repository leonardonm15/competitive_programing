#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const double EPS = 1e-6;

void solve () {
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(k + 1);
    vector<int> b(k + 1);
    vector<double> vels;

    for (int i=0; i < k; i++) cin >> a[i + 1];
    for (int i=0; i < k; i++) cin >> b[i + 1];

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
            int tm = (dist * (a[idx + 1] / b[idx + 1]));
            resp.push_back(tm);
        }
        else {
            int dist = d - a[idx];
            int tm = (dist * (a[idx + 1] - a[idx])) / (b[idx + 1] - b[idx]);
            resp.push_back(b[idx - 1] + tm);
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
