#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        mp[num]++;
    }

    vector<pair<int, int>> arr;
    for (auto [c, v]: mp) {
        arr.push_back({c, v});
    }

    sort(arr.begin(), arr.end());

    int v = -1;
    int qv = -1;
    int resp = 0;
    for (int i = 0; i < (int) arr.size(); i++) {
        if (v == -1) {
            v = arr[i].second;
            qv = 1;
        } else {
            if ((arr[i - 1].first + 1 == arr[i].first) && qv < k) {
                v += arr[i].second;
                qv++;
            } else if ((arr[i - 1].first + 1 == arr[i].first) && qv == k) {
                v -= arr[i - k].second;
                v += arr[i].second;
            } else {
                v = arr[i].second;
                qv = 1;
            }
        }

        /* cout << "---------------------" << endl; */
        /* cout << "arr[i].first -> " << arr[i].first << endl; */
        /* cout << "arr[i].second -> " << arr[i].second << endl; */
        /* cout << "v -> " << v << " - " << i << endl; */
        resp = max(resp, v);
    }

    cout << resp << endl;
}

signed main() {
    int tc; cin >> tc;
    while (tc--) solve();
}
