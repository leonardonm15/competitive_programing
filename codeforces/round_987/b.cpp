#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


string solve2(vector<int>& arr) {
    int n = arr.size();
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == i + 1) continue;
        if (arr[i] != (i + 1) && arr[i + 1] == (i + 1) && abs(arr[i] - arr[i + 1]) == 1) swap(arr[i], arr[i + 1]);
        else flag = false;
    }

    return (flag ? "YES" : "NO");
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve2(arr) << endl;
    /* for (int i = 0; i < n; i++) arr[i] = i + 1; */

    /* do { */
    /*     vector<int> k = arr; */
    /*     cout << "Perm -> "; */
    /*     for (auto v: arr) cout << v << " "; */
    /*     cout << solve2(k) << endl; */
    /* } while (next_permutation(arr.begin(), arr.end())); */
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
