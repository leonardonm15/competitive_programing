#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int bb(int k, vector<int>& arr) { 
    int l = 0;
    int r = arr.size();
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (arr[mid] < k) {
            l = mid + 1;
        } else if (arr[mid] > k) {
            r = mid - 1;
        } else {
            return ans = mid;
        }
    }

    return ans;
}

int t;
void solve () {
    t++;
    int n, k, l, r; cin >> n >> k >> l >> r;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    /* if (t == 1649) { */
    /*     cout << n << "$" << k << "$" << l << "$" << r << "%"; */
    /*     for (auto v: arr) { */
    /*         cout << v << "&"; */
    /*     } */
    /*     cout << endl; */
    /* } */

    vector<int> sarr = arr;

    sort(sarr.begin(), sarr.end());
    sarr.erase(unique(sarr.begin(), sarr.end()), sarr.end());

    vector<int> carr;
    for (auto v: arr) {
        carr.push_back(bb(v, sarr));
    }

    vector<int> min_k(n, -1);
    vector<int> max_k(n, -1);
    vector<int> freq(n);
    int unique = 0;

    int L = 0;
    int R = -1;
    while (L < n) {
        while (R < n && unique < k) {
            R++;
            if (!freq[carr[R]]) unique++;
            freq[carr[R]]++;
        }

        if (unique == k) min_k[L] = R;

        freq[carr[L]]--;
        if (!freq[carr[L]]) unique--;
        L++;
    }

    L = 0;
    R = 0;
    unique = 0;
    while (L < n) {
        while (R < n && unique <= k) {
            if (!freq[carr[R]] && unique == k) break;
            if (!freq[carr[R]]) unique++;
            freq[carr[R]]++;
            R++;
        }

        /* cout << "---------------" << endl; */
        /* cout << "Unique -> " << unique << endl; */
        /* cout << "k -> " << k << endl; */
        /* cout << "L -> " << L << endl; */
        /* cout << "R -> " << R << endl; */
        if (unique >= k) max_k[L] = R - 1;

        freq[carr[L]]--;
        if (!freq[carr[L]]) unique--;
        L++;
        R = max(L, R);
    }

    cout << "min_k -> ";
    for (auto v: min_k) {
        cout << v << " ";
    }
    cout << endl;

    cout << "max_k -> ";
    for (auto v: max_k) {
        cout << v << " ";
    }
    cout << endl;

    int resp = 0;
    for (int i = 0; i < n; i++) {
        if (min_k[i] == -1) continue;

        int min_range = max(l, min_k[i] - i + 1);
        int max_range = min(r, max_k[i] - i + 1);

        /* cout << "--------------------" << endl; */
        /* cout << "i -> " << i << endl; */
        /* cout << "min_range -> " << min_range << endl; */
        /* cout << "max_range -> " << max_range << endl; */

        resp += (max_range - min_range + 1);
    }

    cout << resp << endl;

}

signed main() {
    t = 0;
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
