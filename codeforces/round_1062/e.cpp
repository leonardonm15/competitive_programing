#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int INF = 1e9 + 5;

#define tii tuple<int, int, bool> 

void solve () {
    int n, k, x; cin >> n >> k >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    for (int i = 1; i < n; i++) {
        pq.emplace(max(0ll, arr[i] - arr[i - 1] - 1), arr[i], false);
    }

    int dd = arr[0];
    auto [mdm, _] = pq.top();
    int de = x - arr[n - 1];
    vector<int> resp;
    int comeco = 0;
    int fim = x;
    if (dd >= mdm || de >= mdm) {
        if (dd >= de) {
            resp.push_back(comeco++);
            dd--; k--;
        } else {
            resp.push_back(fim--);
            de--;
            k--;
        }
    }

    pq.emplace(arr[0] - dd, , true);
    pq.emplace(de, (x - arr[n - 1]) - de, true);

    int resp = INF;
    bool broke = false;
    while (k--) {
        auto [dist, start, flag] = pq.top();
        if (dist == 0) broke = true;
        if (flag) {
            pq.emplace(dist - 1, start, true); 
            resp = min(resp, dist - 1);
        }
        else {
            int mid = (dist + 1) / 2;
            resp.push_back(start + mid);
            int d1 = mid - 1;
            int d2 = dist - mid;
            resp = min({resp, d1, d2});
            pq.emplace(d1, start, false);
            pq.emplace(d2, mid, false);
        }
        pq.pop();
    }

    if (broke) cout << 0 << endl;
    else cout << resp + 1 << endl;
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
