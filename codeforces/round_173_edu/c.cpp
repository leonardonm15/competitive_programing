#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

pair<int, int> kadane(vector<int>& arr, int k, int n) {
    int min_sum = 0;
    int max_sum = 0;
    int mx = 0;
    int mn = 0;
    for (int i = k; i < n; i++) {
        mx = max(arr[i], mx + arr[i]);
        mn = min(arr[i], mn + arr[i]);
        min_sum = min(min_sum, mn);
        max_sum = max(max_sum, mx);
    }

    return {min_sum, max_sum};
}
void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    int pos = -1;

    int min_sum = 0;
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] != -1 && arr[i] != 1) {
            pos = i;
            continue;
        }

        min_sum = min(min_sum, arr[i]);
        max_sum = max(max_sum, arr[i]);
    }

    vector<int> resp;
    resp.push_back(0);
    if (pos != -1) {
        auto [k1, k2] = kadane(arr, 0, pos);
        auto [k3, k4] = kadane(arr, pos + 1, n);
        min_sum = min({min_sum, k1, k3});
        max_sum = max({max_sum, k2, k4});


    } else {
        auto [k5, k6] = kadane(arr, 0, n);
        min_sum = min(min_sum, k5);
        max_sum = max(max_sum, k6);
    }

    for (int i = min_sum; i <= max_sum; i++) resp.push_back(i);

    if (pos != -1) {
        
        int min_pref = 0;
        int max_pref = 0;

        int sum = 0;
        for (int i = pos + 1; i < n; i++) {
            sum += arr[i];
            min_pref = min(min_pref, sum);
            max_pref = max(max_pref, sum);
        }

        int min_suf = 0;
        int max_suf = 0;

        sum = 0;
        for (int i = pos - 1; i >= 0; i--) {
            sum += arr[i];
            min_suf = min(min_suf, sum);
            max_suf = max(max_suf, sum);
        }

        for (int i = min_pref + min_suf + arr[pos]; i <= max_pref + max_suf + arr[pos]; i++) {
            resp.push_back(i);
        }
    }

    sort(resp.begin(), resp.end());
    resp.erase(unique(resp.begin(), resp.end()), resp.end());

    cout << resp.size() << endl;
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
